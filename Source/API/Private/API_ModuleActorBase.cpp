#include "API_ModuleActorBase.h"

#include "API_SingletonInstance.h"

AAPI_ModuleActorBase::AAPI_ModuleActorBase()
{
}

void AAPI_ModuleActorBase::BeginPlay()
{
	Super::BeginPlay();

	FAPI_SingletonInstance::Get(this)->RegisterAPIActor(this);
}

void AAPI_ModuleActorBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	FAPI_SingletonInstance::Get(this)->UnRegisterAPIActor(this);
}

void AAPI_ModuleActorBase::OnPixelStreamEvent_Implementation(const FString& EventGuid, const FString& EventFunctionName,
	const FString& EventArgs)
{
}