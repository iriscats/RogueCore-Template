#pragma once
#include "CoreMinimal.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "AsyncLoadCompleteDelegateDelegate.h"
#include "EAsyncLoadPriority.h"
#include "EAsyncPersistence.h"
#include "AsyncManager.generated.h"

class UObject;
UCLASS(Blueprintable)
class UAsyncManager : public UGameInstanceSubsystem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> PermanentReferences;
    
    UAsyncManager();
 
    UFUNCTION(BlueprintCallable)
    TArray<UClass*> SyncLoadClasses(const TArray<TSoftClassPtr<UObject>>& Assets, const EAsyncPersistence persistence);
    UClass* SyncLoadClass(TSoftClassPtr<UObject> Asset, const EAsyncPersistence persistence);
    TArray<UObject*> SyncLoadAssets(const TArray<TSoftObjectPtr<UObject>>& Assets, const EAsyncPersistence persistence);
    UObject* SyncLoadAsset(TSoftObjectPtr<UObject> Asset, const EAsyncPersistence persistence);
    void ReleaseAllHandles();
    void AsyncLoadSoftObjects(const TArray<TSoftObjectPtr<UObject>>& Items, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority);
    void AsyncLoadSoftObject(const TSoftObjectPtr<UObject> Item, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority);
    void AsyncLoadSoftClasses(TArray<TSoftClassPtr<UObject>> Items, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority);
    void AsyncLoadSoftClass(TSoftClassPtr<UObject> Item, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority);
    void AsyncLoadAssets(const TArray<FSoftObjectPath>& Items, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority);
    void AsyncLoadAsset(const FSoftObjectPath& Item, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority);
};
