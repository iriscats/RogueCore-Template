#include "AsyncManager.h"

UAsyncManager::UAsyncManager() {
}

TArray<UClass*> UAsyncManager::SyncLoadClasses(const TArray<TSoftClassPtr<UObject>>& Assets, const EAsyncPersistence persistence) {
    return TArray<UClass*>();
}

UClass* UAsyncManager::SyncLoadClass(TSoftClassPtr<UObject> Asset, const EAsyncPersistence persistence) {
    return NULL;
}

TArray<UObject*> UAsyncManager::SyncLoadAssets(const TArray<TSoftObjectPtr<UObject>>& Assets, const EAsyncPersistence persistence) {
    return TArray<UObject*>();
}

UObject* UAsyncManager::SyncLoadAsset(TSoftObjectPtr<UObject> Asset, const EAsyncPersistence persistence) {
    return NULL;
}

void UAsyncManager::ReleaseAllHandles() {
}

void UAsyncManager::AsyncLoadSoftObjects(const TArray<TSoftObjectPtr<UObject>>& Items, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority) {
}

void UAsyncManager::AsyncLoadSoftObject(const TSoftObjectPtr<UObject> Item, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority) {
}

void UAsyncManager::AsyncLoadSoftClasses(TArray<TSoftClassPtr<UObject>> Items, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority) {
}

void UAsyncManager::AsyncLoadSoftClass(TSoftClassPtr<UObject> Item, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority) {
}

void UAsyncManager::AsyncLoadAssets(const TArray<FSoftObjectPath>& Items, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority) {
}

void UAsyncManager::AsyncLoadAsset(const FSoftObjectPath& Item, EAsyncPersistence persistence, const FAsyncLoadCompleteDelegate& OnLoadComplete, EAsyncLoadPriority Priority) {
}


