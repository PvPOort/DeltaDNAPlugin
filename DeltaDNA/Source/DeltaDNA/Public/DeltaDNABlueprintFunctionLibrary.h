#pragma once

#include "AnalyticsBlueprintLibrary.h"
#include "DeltaDNABlueprintFunctionLibrary.generated.h"

UCLASS()
class DELTADNA_API UDeltaDNABlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "DeltaDNA Analytics")
	static void TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttr>& attributes);
};
