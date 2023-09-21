#include "API_SingletonInstance.h"

#include "API_CoreActor.h"
#include "API_Log.h"

TSharedPtr<FAPI_SingletonInstance> FAPI_SingletonInstance::SingletonInstance = nullptr;

FAPI_SingletonInstance::FAPI_SingletonInstance()
{
}

FAPI_SingletonInstance::~FAPI_SingletonInstance()
{
	if (SingletonInstance != nullptr)
	{
		SingletonInstance = nullptr;
	}	
}

TSharedPtr<FAPI_SingletonInstance> FAPI_SingletonInstance::Get(const UObject* WorldContextObject)
{
	if (!SingletonInstance.IsValid())
	{
		SingletonInstance = MakeShareable(new FAPI_SingletonInstance);
	}

	if (SingletonInstance->API_CoreActor == nullptr || !SingletonInstance->API_CoreActor->IsValidLowLevel())
	{
		SingletonInstance->SetGlobalWorld(WorldContextObject);
		SingletonInstance->CreateCoreActor(WorldContextObject);
		// SingletonInstance->Settings = GetDefault<USuperAPI_Settings>();
		// if (SingletonInstance->Settings)
		// {
		// 	if (SingletonInstance->Settings->Information_GatheringUrl != TEXT(""))
		// 	{
		// 		SingletonInstance->GetInformation_GatheringUrl(SingletonInstance->Settings->Information_GatheringUrl);
		// 	}
		//
		// 	SingletonInstance->mAllCADDatumMap.Append(SingletonInstance->Settings->CADDatumMap);
		// }
		//
		// SingletonInstance->CreateRayHitCoreActorIntoLevel(WorldContextObject);
	}
	return SingletonInstance;
}

TSharedPtr<FAPI_SingletonInstance> FAPI_SingletonInstance::Get()
{
	if (!SingletonInstance.IsValid())
	{
		SingletonInstance = MakeShareable(new FAPI_SingletonInstance);
	}
	return SingletonInstance;
}

AAPI_CoreActor* FAPI_SingletonInstance::GetAPICoreActor() const
{
	return API_CoreActor.Get();
}

void FAPI_SingletonInstance::RegisterAPIActor(UObject* obj)
{
	APIModuleActors.AddUnique(obj);
}

void FAPI_SingletonInstance::UnRegisterAPIActor(UObject* obj)
{
	APIModuleActors.RemoveSingle(obj);
}

AAPI_CoreActor* FAPI_SingletonInstance::CreateCoreActor(const UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World != nullptr)
	{
		API_CoreActor = World->SpawnActor<AAPI_CoreActor>();
		return API_CoreActor.Get();
	}
	return nullptr;
}

void FAPI_SingletonInstance::SetGlobalWorld(const UObject* WorldContextObject)
{
	GlobalWorld = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	FString OutputLog = FString::Printf(TEXT("%s"), GlobalWorld != nullptr ? *GetNameSafe(GlobalWorld.Get()) : *FString(TEXT("nullptr")));
	UE_LOG(API_Log, Log, TEXT("FAPI_SingletonInstance::SetGlobalWorld  GlobalWorld=[%s]"), *OutputLog);
}
