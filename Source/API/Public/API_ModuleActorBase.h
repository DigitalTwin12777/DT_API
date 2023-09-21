#pragma once

#include "CoreMinimal.h"
#include "Interface/IAPI_PixStreamEventInterface.h"
#include "API_ModuleActorBase.generated.h"

UCLASS()
class API_API AAPI_ModuleActorBase : public AActor, public IAPI_PixelStreamEventInterface
{
	GENERATED_BODY()
public:
	AAPI_ModuleActorBase();

protected:
	// ~Begin AActor Interface
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason)override;
	// ~End AActor Interface

	// ~Begin IAPI_PixelStreamEventInterface Interface
	virtual void OnPixelStreamEvent_Implementation(const FString& EventGuid, const FString& EventFunctionName, const FString& EventArgs) override;
	// ~End IAPI_PixelStreamEventInterface Interface
};