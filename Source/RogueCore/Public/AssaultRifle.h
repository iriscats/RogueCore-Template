#pragma once
#include "CoreMinimal.h"
#include "HitscanWeapon.h"
#include "Templates/SubclassOf.h"
#include "AssaultRifle.generated.h"

class AActor;
class UFSDPhysicalMaterial;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class AAssaultRifle : public AHitscanWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float KillsResetAccuracyDuration;
    
    bool KillsTriggersStatusEffect;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> KillTriggeredStatusEffect;
    AAssaultRifle(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnTimerElapsed();
    void OnEnemyKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_ResetAccuracy();
};
