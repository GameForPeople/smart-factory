// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SensorFusion.h"

#include "SensorFusionSettings.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"

#ifdef LOAD_DLL
#include "IPluginManager.h"
#include "Paths.h"
#endif

#define LOCTEXT_NAMESPACE "FSensorFusionModule"

#define SETTING_MODULE_NAME		"Settings"
#define SETTING_CONTAINER_NAME	"Project"
#define SETTING_CATEGORY_NAME	"SensorFusion"
#define SETTING_SECTION_NAME	"General"

void FSensorFusionModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(LogTemp, Warning, TEXT("+++ SensorFusion Module Start..."));

	RegisterSettings();
}

void FSensorFusionModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UE_LOG(LogTemp, Warning, TEXT("+++ SensorFusion Module Shutdown..."));

	if (UObjectInitialized())
	{
		UnregisterSettings();
	}
}


bool FSensorFusionModule::HandleSettingsSaved()
{
	USensorFusionSettings* Settings = GetMutableDefault<USensorFusionSettings>();
	bool ResaveSettings = false;

	// You can put any validation code in here and resave the settings in case an invalid
	// value has been entered

	if (ResaveSettings)
	{
		Settings->SaveConfig();
	}

	return true;
}

void FSensorFusionModule::RegisterSettings()
{
	// Registering some settings is just a matter of exposing the default UObject of
	// your desired class, feel free to add here all those settings you want to expose
	// to your LDs or artists.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>(SETTING_MODULE_NAME))
	{
		// Create the new category
		ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer(SETTING_CONTAINER_NAME);

		SettingsContainer->DescribeCategory(SETTING_CATEGORY_NAME,
			LOCTEXT("RuntimeWDCategoryName", SETTING_CATEGORY_NAME),
			LOCTEXT("RuntimeWDCategoryDescription", "Game configuration for the SensorFusion module"));

		// Register the settings
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings(SETTING_CONTAINER_NAME, SETTING_CATEGORY_NAME, SETTING_SECTION_NAME,
			LOCTEXT("RuntimeGeneralSettingsName", SETTING_SECTION_NAME),
			LOCTEXT("RuntimeGeneralSettingsDescription", "Base configuration for SensorFusion module"),
			GetMutableDefault<USensorFusionSettings>()
		);

		// Register the save handler to your settings, you might want to use it to
		// validate those or just act to settings changes.
		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &FSensorFusionModule::HandleSettingsSaved);
		}
	}
}

void FSensorFusionModule::UnregisterSettings()
{
	// Ensure to unregister all of your registered settings here, hot-reload would
	// otherwise yield unexpected results.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>(SETTING_MODULE_NAME))
	{
		SettingsModule->UnregisterSettings(SETTING_CONTAINER_NAME, SETTING_CATEGORY_NAME, SETTING_SECTION_NAME);
	}
}

#ifdef LOAD_DLL
void FSensorFusionModule::LoadDependency(void*& Handle)
{
#if PLATFORM_WINDOWS
	#if PLATFORM_64BITS
	FString BaseDir = IPluginManager::Get().FindPlugin("SensorFusion")->GetBaseDir();
	const FString LibDir = FPaths::Combine(*BaseDir, TEXT("Dependencies"), TEXT("x64"));
	const FString LibName = TEXT("glew32");
	//const FString LibDir = FPaths::Combine(*SDKDir, TEXT("Win64"));

	FString Lib = LibName + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = LibDir.IsEmpty() ? *Lib : FPaths::Combine(*LibDir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);
	if (Handle == nullptr)
	{
		return;
	}
	#endif
#endif
}

void FSensorFusionModule::FreeDependency(void*& Handle)
{
#if !PLATFORM_LINUX
	if (Handle != nullptr)
	{
		FPlatformProcess::FreeDllHandle(Handle);
		Handle = nullptr;
	}
#endif
}
#endif //LOAD_DLL


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSensorFusionModule, SensorFusion)