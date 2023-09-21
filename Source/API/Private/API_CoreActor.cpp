#include "API_CoreActor.h"
#include "PixelStreamingInputComponent.h"

AAPI_CoreActor::AAPI_CoreActor()
{
	PixelStreamingInput = CreateDefaultSubobject<UPixelStreamingInput>(TEXT("PixelStreamingInput"));
}

void AAPI_CoreActor::BeginPlay()
{
	Super::BeginPlay();

	if (ensureMsgf(PixelStreamingInput != nullptr, TEXT("error:: [AAPI_CoreActor::BeginPlay] PixelStreamingInput is nullptr")))
	{
		PixelStreamingInput->OnInputEvent.AddDynamic(this, &OnPixelStreamingInputEvent);
	}
}

void AAPI_CoreActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (PixelStreamingInput != nullptr)
	{
		PixelStreamingInput->OnInputEvent.RemoveAll(this);
	}
}

void AAPI_CoreActor::OnPixelStreamingInputEvent(const FString& Descriptor)
{
}
