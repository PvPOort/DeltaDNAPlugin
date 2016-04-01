#ifndef PlatformDeltaDNA_h
#define PlatformDeltaDNA_h

#include "DeltaDNAPrivatePCH.h"

#if PLATFORM_IOS
#import <Foundation/Foundation.h>
#include "DeltaDNASDK/DDNASDK.h"

@interface IOSDeltaDNA : NSObject

+(bool) InitWithID:(NSString*) appID collectURL:(NSString*) collectURL engageURL:(NSString*) engageURL;
+(void) TrackEvent:(NSString*) eventName withProperies:(NSDictionary *)properties;

@end
#endif // PLATFORM_IOS

class PlatformDeltaDNAHelper
{
protected:

    PlatformDeltaDNAHelper();
public:
	virtual ~PlatformDeltaDNAHelper() {};
    
    static bool InitDeltaDNA(const FString& apiKey, const FString& collectURL, const FString& engageURL);
    static void TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttribute>& attributes);
};

#endif /* PlatformDeltaDNA_h */
