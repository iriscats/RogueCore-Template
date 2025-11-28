#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "DelegateDelegate.h"
#include "OnSectionLogAddedDelegate.h"
#include "SpawnLog.h"
#include "SpawnLogger.generated.h"

UCLASS(Abstract, Blueprintable)
class USpawnLogger : public UObject {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> SpawnLocations;
    
    FSpawnLog log;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnLogAdded;
    FOnSectionLogAdded OnSectionLogAdded;
    USpawnLogger();
    UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(WorldContext="WorldContextObject"))
    void ShowSpawnLocations(UObject* WorldContextObject) const;
};
