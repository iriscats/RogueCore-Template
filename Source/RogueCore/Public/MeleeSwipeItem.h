#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AbilityItem.h"
#include "MeleeSwipeData.h"
#include "MeleeSwipeItem.generated.h"

class UAnimMontage;
class UAudioComponent;
class UDamageAsset;
class UNiagaraSystem;
class USoundCue;
class UStaticMesh;
class UTerrainMaterial;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AMeleeSwipeItem : public AAbilityItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* SlicerSounds;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* CarveMesh;
    UTerrainMaterial* MagmaMaterial;
    UNiagaraSystem* HitEffect;
    UNiagaraSystem* BeamEffect;
    USoundCue* ImpactSound;
    USoundCue* SwipeHitConfirmSond;
    UAnimMontage* FP_AttackAnim;
    UAnimMontage* TP_AttackAnim;
    UDamageAsset* Damage;
    FVector CarveScale;
    FVector MagmaScale;
    float MinRange;
    float MaxRange;
    float Width;
    float AttackThickness;
    float AngleLimit;
    float VerticalOffset;
    float VerticalCarveOffset;
    bool ShowDebugBox;
    bool RequireFullyEquipped;
    AMeleeSwipeItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHits(const FMeleeSwipeData& HitData);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_PerformSwipe(FVector Origin, FVector carveOffset, FVector cameraDirection);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Cheat_AddPlasmaSwoosh();
    void Cheat_AddHotPlasma();
    UFUNCTION(BlueprintCallable)
    void AttackAnimEnded();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowSwipe(FVector Origin, FVector cameraDirection);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowHits(const FMeleeSwipeData& HitData);
};
