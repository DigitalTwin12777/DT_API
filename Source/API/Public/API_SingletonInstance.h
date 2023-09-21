#pragma once

#include "CoreMinimal.h"

class AAPI_CoreActor;

class FAPI_SingletonInstance : public TSharedFromThis<FAPI_SingletonInstance>
{
public:
	FAPI_SingletonInstance();
	~FAPI_SingletonInstance();
	
	static TSharedPtr<FAPI_SingletonInstance> Get(const UObject* WorldContextObject);
	static TSharedPtr<FAPI_SingletonInstance> Get();

	AAPI_CoreActor* GetAPICoreActor() const;
	FORCEINLINE const TArray<UObject*>& GetAPIModuleActors() const { return APIModuleActors; }

	void RegisterAPIActor(UObject* obj);
	void UnRegisterAPIActor(UObject* obj);

protected:
	AAPI_CoreActor* CreateCoreActor(const UObject* WorldContextObject);
	void SetGlobalWorld(const UObject* WorldContextObject);

protected:
	TWeakObjectPtr<AAPI_CoreActor> API_CoreActor;
	TWeakObjectPtr<UWorld> GlobalWorld;

	TArray<UObject*> APIModuleActors;

private:
	static TSharedPtr<FAPI_SingletonInstance> SingletonInstance;
};