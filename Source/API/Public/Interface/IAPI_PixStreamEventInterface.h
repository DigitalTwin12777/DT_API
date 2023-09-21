#pragma once

#include "CoreMinimal.h"
#include "IAPI_PixStreamEventInterface.generated.h"

UINTERFACE(Blueprintable)
class API_API UAPI_PixelStreamEventInterface : public UInterface
{
	GENERATED_BODY()
};

class API_API IAPI_PixelStreamEventInterface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = API, meta = (DisplayName = "PixelStreamEvent"))
	virtual void OnPixelStreamEvent(const FString& EventGuid, const FString& EventFunctionName, const FString& EventArgs);
};