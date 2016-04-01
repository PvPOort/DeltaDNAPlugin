#include "DeltaDNAPrivatePCH.h"
#include "DeltaDNABlueprintFunctionLibrary.h"
#include "DeltaDNA.h"

DEFINE_LOG_CATEGORY_STATIC(LogDeltaDNAAnalytics, Log, All);

void UDeltaDNABlueprintFunctionLibrary::TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttr>& attributes)
{
	FDeltaDNAModule *moduleInstance = &FDeltaDNAModule::Get();
	if (moduleInstance)
	{
		TArray<FAnalyticsEventAttribute> convertedAttributes;

		for (int32 i = 0; i < attributes.Num(); i++)
		{
			convertedAttributes.Add(FAnalyticsEventAttribute(attributes[i].Name, attributes[i].Value));
		}

		moduleInstance->TrackEvent(eventName, convertedAttributes);
	}
	else
	{
		UE_LOG(LogDeltaDNAAnalytics, Warning, TEXT("UDeltaDNABlueprintFunctionLibrary::TrackEvent: DeltaDNA module is NULL"));
	}
}


