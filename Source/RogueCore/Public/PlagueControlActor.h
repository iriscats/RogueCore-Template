#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlacementObstruction.h"
#include "Templates/SubclassOf.h"
#include "PlagueControlActor.generated.h"

class ACleanupPodItem;
class APlagueInfectionNode;
class APlayerCharacter;
class UNiagaraComponent;
class UPlagueUsable;
class UTerrainMaterial;
UCLASS(Blueprintable, NoExport)
class APlagueControlActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FPlacementObstruction> Obstructions;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* DebrisLightSystem;
    UPlagueUsable* CallWeaponPodUsable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* TargetPlagueMaterial;
    TSubclassOf<ACleanupPodItem> CleanupPodItem;
    float MinTimeBetweenWeaponPods;
    float MinDistBetweenPods;
    float MaxDistFromCenter;
    float CanCallPodDistance;
    float IgnoreDebrisLightSphere;
    float DebrisLightDistanceFromGround;
    float RemoveDebrisLightUpdateRate;
    bool DebugDrawDebrisLight;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlagueInfectionNode> TargetedPlagueNode;
    APlagueControlActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SpawnPodHack(APlayerCharacter* Player) const;
    UFUNCTION(BlueprintCallable)
    void SetCanUseWeaponPod(bool Value);
    void PushDebrisLights();
    void EquipPlaguePod(APlayerCharacter* Player);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanDropWeaponPod(float& TimeLeft);
};
