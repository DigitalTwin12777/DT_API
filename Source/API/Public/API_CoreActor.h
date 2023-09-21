#pragma once

#include "CoreMinimal.h"
#include "API_CoreActor.generated.h"

class UPixelStreamingInput;

UCLASS()
class API_API AAPI_CoreActor : public AActor
{
	GENERATED_BODY()
public:
	AAPI_CoreActor();

protected:
	// ~Begin AActor Interface
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason)override;
	// ~End AActor Interface

	UFUNCTION()
	void OnPixelStreamingInputEvent(const FString & Descriptor);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "API", meta=(AllowPrivateAccess))
	TObjectPtr<UPixelStreamingInput> PixelStreamingInput;
};