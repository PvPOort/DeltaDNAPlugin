// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

#include "IAnalyticsProviderModule.h"
#include "IAnalyticsProvider.h"

class FDeltaDNAModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FDeltaDNAModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FDeltaDNAModule >("DeltaDNA");
	}

	virtual void TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttribute>& attributes);
};