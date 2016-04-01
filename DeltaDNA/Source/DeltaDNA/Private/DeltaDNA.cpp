// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "DeltaDNAPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FDeltaDNAModule"

void FDeltaDNAModule::StartupModule()
{

}

void FDeltaDNAModule::ShutdownModule()
{

}

void FDeltaDNAModule::TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttribute>& attributes)
{
	PlatformDeltaDNAHelper::TrackEvent(eventName, attributes);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDeltaDNAModule, DeltaDNA)