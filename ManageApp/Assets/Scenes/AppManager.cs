﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Threading;

using System.Runtime.InteropServices;

using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

using UnityEngine.Networking;
using UnityEngine.UI;
using System.Net.NetworkInformation;

public class AppManager : MonoBehaviour {

    private /*volatile*/ bool isOnNetwork = false;
    private int lockValue = 0;

    private string LOCAL_HOST_IP = "127.0.0.1";
    private string PUBLIC_SERVER_IP = "13.125.73.63";
    private short SERVER_LISTEN_PORT = 9000;
    private int COMMON_PASSWORD = 19942019;

    public Socket socket = null;

    private bool onoffFactoryFlag = false;

    private int nowCameraIndex = 0;

    private Color[] cameraDataBuffer = new Color[64 * 64 /** 3*/];
    public byte[] dataSendBuffer = new byte[100];
    public byte[] cameraDataRecvBuffer = new byte[64 * 64 * 3];  // [3][300][300]

    GameObject titleImage;
    GameObject cameraImage;
    GameObject loginImage;
    GameObject newOrderImage;

    Text totalOrder;
    int totalOrderCount = 21;

    Text carType;
    Text colorType;
    Text tireType;

    Text textBlack;
    int blackCount = 6;

    Text textWhite;
    int whiteCount = 3;

    Text textRed;
    int redCount = 5;

    Text textBlue;
    int blueCount = 4;

    Text textGreen;
    int greenCount = 0;

    Text textYellow;
    int yellowCount = 3;


    Texture2D tex;

    enum CLIENT_TYPE : byte
    {
        Client = 0
        , Manager = 1
        , Factory = 2
    };

    enum PROTOCOL_TYPE : byte
    {
          OnOffFactory = 0
        , ChangeCamera = 1
        , NeedCameraData = 2
        , NeedUserData = 3
    };

    // Use this for initialization
    void Start ()
    {
        socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

        socket.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.SendTimeout, 10000);
        socket.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveTimeout, 10000);

        titleImage = GameObject.Find("Image_Title");
        titleImage.GetComponent<Image>().color = new Color(1.0f, 1.0f, 1.0f, 1.0f);

        cameraImage = GameObject.Find("Image_Camera");
        //cameraImage.AddComponent<Renderer>();

        loginImage = GameObject.Find("OnOff_Login").transform.Find("LOGIN_UI").gameObject;
        loginImage.SetActive(true);

        newOrderImage = GameObject.Find("NewOrder").transform.Find("NewOrderBack").gameObject;
        newOrderImage.SetActive(false);

        totalOrder = GameObject.Find("Text_Count").GetComponent<Text>();
        carType = GameObject.Find("Text_CarType").GetComponent<Text>();
        colorType = GameObject.Find("Text_ColorType").GetComponent<Text>();
        tireType = GameObject.Find("Text_TireType").GetComponent<Text>();
        textBlack = GameObject.Find("Text_Black").GetComponent<Text>();
        textWhite = GameObject.Find("Text_White").GetComponent<Text>();
        textRed = GameObject.Find("Text_Red").GetComponent<Text>();
        textBlue = GameObject.Find("Text_Blue").GetComponent<Text>();
        textGreen = GameObject.Find("Text_Green").GetComponent<Text>();
        textYellow = GameObject.Find("Text_Yellow").GetComponent<Text>();

        StartCoroutine(TitleCoroutine());
    }

    public IEnumerator TitleCoroutine()
    {
        float alphaValue = 1.0f;

        yield return new WaitForSeconds(2.0f);

        while (alphaValue > 0)
        {
            alphaValue = alphaValue - 0.01f;

            Color tempColor = titleImage.GetComponent<Image>().color;
            tempColor.a = alphaValue;
            titleImage.GetComponent<Image>().color = tempColor;

            yield return new WaitForSeconds(0.01f);
        }

        titleImage.GetComponent<Image>().raycastTarget = false;
    }

    void Quit()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false; //play모드를 false로.
                                                         //#elif UNITY_WEBPLAYER
                                                         //        Application.OpenURL("http://google.com"); //구글웹으로 전환
#else
                        Application.Quit(); //어플리케이션 종료
#endif
    }

    void Lock()
    {
        while (Interlocked.CompareExchange(ref lockValue, 1, 0) != 0)
        {
        }
    }

    void UnLock()
    {
        while (Interlocked.CompareExchange(ref lockValue, 0, 1) != 1)
        {
            Debug.Log("발생할 일 절대 없어야함");
        }
    }

    public void StartNetwork(int serverType)
    {
        loginImage.SetActive(false);

        Debug.Log("네트워크 시작! " + serverType);

        System.Net.IPAddress ipAddr;

        if (serverType == 0)
        {
            ipAddr = System.Net.IPAddress.Parse(LOCAL_HOST_IP);
        }
        else
        {
            ipAddr = System.Net.IPAddress.Parse(PUBLIC_SERVER_IP);
        }

        Lock();

        try
        {
            IPEndPoint ipEndPoint = new System.Net.IPEndPoint(ipAddr, SERVER_LISTEN_PORT);
            socket.Connect(ipEndPoint);
        }
        catch (SocketException SCE)
        {
            Debug.Log("Socket connect error! : " + SCE.ToString());
            Quit();
            return;
        }

        // Buffer.BlockCopy(BitConverter.GetBytes(CLIENT_TYPE.Manager), 0, dataSendBuffer, 0, 1);
        dataSendBuffer[0] = (byte)(CLIENT_TYPE.Manager);
        Buffer.BlockCopy(BitConverter.GetBytes(COMMON_PASSWORD), 0, dataSendBuffer, 1, 4);

        socket.Send(dataSendBuffer, 29, SocketFlags.None);

        UnLock();
        isOnNetwork = true;
    }

    void ProcessCameraData()
    {
        Lock();

        //Buffer.BlockCopy(BitConverter.GetBytes(PROTOCOL_TYPE.NeedCameraData), 0, dataSendBuffer, 0, 1);
        dataSendBuffer[0] = (byte)(PROTOCOL_TYPE.NeedCameraData);
        socket.Send(dataSendBuffer, 1, SocketFlags.None);

        try
        {
            socket.Receive(cameraDataRecvBuffer);
        }
        catch (SocketException SCE)
        {
            Debug.Log("Socket connect error! : " + SCE.ToString());
            Quit();
            return;
        }

        UnLock();

        for (int i = 0; i < 64 * 64; ++i)
        {
            if (i % 64 == 0)
            {
                Debug.Log("X : " + (i / 64)  + ", Y : " + (i % 64) + ", R : " + cameraDataRecvBuffer[3 * i + 0] + ", G : " + cameraDataRecvBuffer[3 * i + 1] + ", B : " + cameraDataRecvBuffer[3 * i + 2]);
            }

            cameraDataBuffer[i] = new Color(cameraDataRecvBuffer[3 * i + 0] / 255.0f
                , (cameraDataRecvBuffer[3 * i + 1]) / 255.0f
                , (cameraDataRecvBuffer[3 * i + 2]) / 255.0f
                , 1);
        }

        tex = new Texture2D(64, 64, TextureFormat.RGB24, false);
        tex.SetPixels(0, 0, 64, 64, cameraDataBuffer);
        cameraImage.GetComponent<Renderer>().material.mainTexture = tex;
        tex.Apply();
    }

    void ProcessClientOrder()
    {
        Lock();

        //Buffer.BlockCopy(BitConverter.GetBytes(PROTOCOL_TYPE.NeedCameraData), 0, dataSendBuffer, 0, 1);
        dataSendBuffer[0] = (byte)(PROTOCOL_TYPE.NeedUserData);
        socket.Send(dataSendBuffer, 1, SocketFlags.None);

        try
        {
            socket.Receive(cameraDataRecvBuffer);
        }
        catch (SocketException SCE)
        {
            Debug.Log("Socket connect error! : " + SCE.ToString());
            Quit();
            return;
        }

        UnLock();

        if(cameraDataRecvBuffer[0] == (byte)(0))
        {
            return;
        }

        StartCoroutine(NewOrderCoroutine());

        int carTypeBuffer = (int)cameraDataRecvBuffer[1];
        int colorTypeBuffer = (int)cameraDataRecvBuffer[2];
        int tireTypeBuffer = (int)cameraDataRecvBuffer[3];

        carType.text = carTypeBuffer.ToString();
        colorType.text = colorTypeBuffer.ToString();
        tireType.text = tireTypeBuffer.ToString();

        ++totalOrderCount;
        totalOrder.text = totalOrderCount.ToString();

        switch(colorTypeBuffer)
        {
            case 0:
                ++blackCount;
                textBlack.text = blackCount.ToString();
                break;
            case 1:
                ++whiteCount;
                textWhite.text = whiteCount.ToString();
                break;
            case 2:
                ++redCount;
                textRed.text = redCount.ToString();
                break;
            case 3:
                ++blueCount;
                textBlue.text = blueCount.ToString();
                break;
            case 4:
                ++greenCount;
                textGreen.text = greenCount.ToString();
                break;
            case 5:
                ++yellowCount;
                textYellow.text = yellowCount.ToString();
                break;
        }
    }

    public IEnumerator NewOrderCoroutine()
    {
        newOrderImage.SetActive(true);

        yield return new WaitForSeconds(1.0f);

        newOrderImage.SetActive(false);
    }

    public void ProcessOnOff(bool isOnOff)
    {
        if (!isOnNetwork) { return; }
        if (onoffFactoryFlag == isOnOff) { return; }
        onoffFactoryFlag = isOnOff;

        Lock();

        // Buffer.BlockCopy(BitConverter.GetBytes(PROTOCOL_TYPE.OnOffFactory), 0, dataSendBuffer, 0, 1);
        dataSendBuffer[0] = (byte)(PROTOCOL_TYPE.OnOffFactory);
        socket.Send(dataSendBuffer, 1, SocketFlags.None);

        // Buffer.BlockCopy(BitConverter.GetBytes(onoffFactoryFlag), 0, dataSendBuffer, 0, 1);
        dataSendBuffer[0] = Convert.ToByte(onoffFactoryFlag);
        socket.Send(dataSendBuffer, 1, SocketFlags.None);

        UnLock();
    }

    public void ProcessCameraIndex(int cameraIndex)
    {
        if (!isOnNetwork) { return; }
        if (nowCameraIndex == cameraIndex) { return; }
        nowCameraIndex = cameraIndex;

        Lock();

        //Buffer.BlockCopy(BitConverter.GetBytes(PROTOCOL_TYPE.ChangeCamera), 0, dataSendBuffer, 0, 1);
        dataSendBuffer[0] = (byte)(PROTOCOL_TYPE.ChangeCamera);
        socket.Send(dataSendBuffer, 1, SocketFlags.None);

        Buffer.BlockCopy(BitConverter.GetBytes(nowCameraIndex), 0, dataSendBuffer, 0, 4);
        socket.Send(dataSendBuffer, 4, SocketFlags.None);

        UnLock();
    }

    // Update is called once per frame
    void Update ()
    {
        if (isOnNetwork) { ProcessClientOrder(); }
    }
}
