// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"


class FSensorFusionModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	// Callback for when the settings were saved.
	bool HandleSettingsSaved();

	void RegisterSettings();
	void UnregisterSettings();

#ifdef LOAD_DLL
	void LoadDependency(void*& Handle);
	void FreeDependency(void*& Handle);
#endif
};