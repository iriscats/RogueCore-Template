#pragma once
#include "CoreMinimal.h"
#include "SpecialEventSpawner.h"
#include "TimedSpecialEventSpawner.generated.h"

class AActor;
class UObject;
UCLASS(Blueprintable, EditInlineNew)
class UTimedSpecialEventSpawner : public USpecialEventSpawner {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    TSoftClassPtr<AActor> EventActor;

    float MinTime;

    float MaxTime;

    UTimedSpecialEventSpawner();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)

    static void UnblockEventSpawn(UObject* blocker);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> BlockStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> EventActor;
    float MinTime;
    float MaxTime;
    UTimedSpecialEventSpawner();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void UnblockEventSpawn(UObject* blocker);
    UFUNCTION(BlueprintCallable)
    void SpawnEvent() const;
    static void BlockEventSpawn(UObject* blocker);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreEventSpawnsBlocked() const;
};
