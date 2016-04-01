#include "DeltaDNAPrivatePCH.h"

#if PLATFORM_IOS

@interface DeltaDNAEventHandler : NSObject
{

}

+(id)StaticInit;
@end

@implementation DeltaDNAEventHandler

+ (id)StaticInit
{
	DeltaDNAEventHandler *instance = [[DeltaDNAEventHandler alloc] init];

	if (instance)
	{
		[[NSNotificationCenter defaultCenter] addObserver:instance
			selector : @selector(didFinishLaunchWithOptions : )
					   name:UIApplicationDidBecomeActiveNotification object : nil];
	}

	return instance;
}

-(void)didFinishLaunchWithOptions:(UIApplication *)application
{
	NSString *appID = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"DeltaDNAApiKey"];
	NSString *collectURL = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"DeltaDNACollectURL"];
	NSString *engageURL = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"DeltaDNAEngageURL"];

	if (appID)
	{
		PlatformDeltaDNAHelper::InitDeltaDNA(FString(appID), FString(collectURL), FString(engageURL));
	}
}

@end

static DeltaDNAEventHandler *EventHandlerStaticInitializer = [DeltaDNAEventHandler StaticInit];

@implementation IOSDeltaDNA

+(bool) InitWithID:(NSString*)appID collectURL : (NSString*)collectURL engageURL : (NSString*)engageURL;
{    
	DDNASDK *sdk = DDNASDK.sharedInstance;

	if (sdk)
	{
		[sdk startWithEnvironmentKey : appID
			collectURL : collectURL
			engageURL : engageURL];
	}

	return true;
}

+(void) TrackEvent:(NSString*) eventName withProperies:(NSDictionary *)properties
{
	dispatch_async(dispatch_get_main_queue(), ^
	{
		DDNASDK *ddna = DDNASDK.sharedInstance;

		if (ddna)
		{
			[ddna recordEvent : eventName withEventDictionary : properties];
		}
	});
}

@end
#endif // PLATFORM_IOS


bool PlatformDeltaDNAHelper::InitDeltaDNA(const FString& apiKey, const FString& collectURL, const FString& engageURL)
{
#if PLATFORM_IOS
    return [IOSDeltaDNA InitWithID:[NSString stringWithFString: apiKey] 
		collectURL: [NSString stringWithFString : collectURL] 
		engageURL: [NSString stringWithFString : engageURL]];
#endif // PLATFORM_IOS

	return false;
}

void PlatformDeltaDNAHelper::TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttribute>& attributes)
{
#if PLATFORM_IOS    
	NSString* convertedEventName = [NSString stringWithFString : eventName];
	const int32 attrCount = attributes.Num();
	if (attrCount > 0)
	{
		NSDictionary* attributesDict = [NSMutableDictionary dictionaryWithCapacity : attrCount];
		for (auto attr : attributes)
		{
			NSString* attrName = [NSString stringWithFString : attr.AttrName];
			NSString* attrValue = [NSString stringWithFString : attr.AttrValue];
			[attributesDict setValue : attrValue forKey : attrName];
		}
		
		[IOSDeltaDNA TrackEvent : convertedEventName withProperies : attributesDict];
	}
#endif // PLATFORM_IOS
}
