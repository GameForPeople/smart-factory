using System.Collections;
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
using System.Net.NetworkInformation;

public class AppManager : MonoBehaviour {

    private volatile bool isOnNetwork = false;
    
    private string LOCAL_HOST_IP = "127.0.0.1";
    private string PUBLIC_SERVER_IP = "13.125.73.63";
    private short SERVER_LISTEN_PORT = 9000;
    private int COMMON_PASSWORD = 19942019;

    public Socket socket = null;

    private int nowCameraIndex = 0;
    private char[3][200][200] cameraDataBuffer;

    private bool onoffFactoryFlag = false;

    public byte[] dataSendBuffer = new byte[100];
    public byte[] cameraDataRecvBuffer = new byte[3][300][300];

    enum CLIENT_TYPE
    {
        Client = 0
        , Manager = 1
        , Factory = 2
    };

    enum PROTOCOL_TYPE
    {
          OnOffFactory = 0
        , ChangeCamera = 1
        , NeedCameraData = 2
    };

    // Use this for initialization
    void Start ()
    {
        socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

        socket.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.SendTimeout, 10000);
        socket.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveTimeout, 10000);

        try
        {
            ipAddr = System.Net.IPAddress.Parse(LOCAL_HOST_IP);
            IPEndPoint ipEndPoint = new System.Net.IPEndPoint(ipAddr, SERVER_LISTEN_PORT);
            socket.Connect(ipEndPoint);
        }
        catch (SocketException SCE)
        {
            Debug.Log("Socket connect error! : " + SCE.ToString());
            GameObject.Find("GameCores").transform.Find("AppQuitManager").GetComponent<AppQuitManager>().Quit(true, 1);
            return;
        }

        Buffer.BlockCopy(BitConverter.GetBytes(CLIENT_TYPE.Manager), 0, dataSendBuffer, 0, 1);
        socket.Send(dataSendBuffer, 1, SocketFlags.None);
    }

    void ProcessCameraData()
    {
        Buffer.BlockCopy(BitConverter.GetBytes(PROTOCOL_TYPE.NeedCameraData), 0, dataSendBuffer, 0, 1);
        socket.Send(dataSendBuffer, 1, SocketFlags.None);

        try
        {
            socket.Receive(cameraDataRecvBuffer);
        }
        catch (SocketException SCE)
        {
            Debug.Log("Socket connect error! : " + SCE.ToString());
            GameObject.Find("GameCores").transform.Find("AppQuitManager").GetComponent<AppQuitManager>().Quit(true, 1);
            return;
        }
    }

    public void ProcessOnOff(bool isOnOff)
    {
        if (onoffFactoryFlag == isOnOff) { return; }
        onoffFactoryFlag = isOnOff;

        Buffer.BlockCopy(BitConverter.GetBytes(PROTOCOL_TYPE.OnOffFactory), 0, dataSendBuffer, 0, 1);
        socket.Send(dataSendBuffer, 1, SocketFlags.None);

        Buffer.BlockCopy(BitConverter.GetBytes(onoffFactoryFlag), 0, dataSendBuffer, 0, 1);
        socket.Send(dataSendBuffer, 1, SocketFlags.None);
    }

    public void ProcessCameraIndex(int cameraIndex)
    {
        if (nowCameraIndex == cameraIndex) { return; }
        nowCameraIndex = cameraIndex;

        Buffer.BlockCopy(BitConverter.GetBytes(PROTOCOL_TYPE.ChangeCamera), 0, dataSendBuffer, 0, 1);
        socket.Send(dataSendBuffer, 1, SocketFlags.None);

        Buffer.BlockCopy(BitConverter.GetBytes(nowCameraIndex), 0, dataSendBuffer, 0, 4);
        socket.Send(dataSendBuffer, 4, SocketFlags.None);
    }

    // Update is called once per frame
    void Update () {
		
	}
}
