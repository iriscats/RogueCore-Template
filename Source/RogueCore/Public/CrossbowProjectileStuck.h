#pragma once
#include "CoreMinimal.h"
#include "ECrossbowStuckType.h"
#include "FSDPhysicsActor.h"
#include "Templates/SubclassOf.h"
#include "CrossbowProjectileStuck.generated.h"


class ACrossbowProjectileBase;
class UCrossbowStuckProjectileEffectBanshee;
class UHealthComponentBase;
class UNiagaraComponent;
class URecallableProjectileComponent;
class USceneComponent;
class USphereComponent;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class ACrossbowProjectileStuck : public AFSDPhysicsActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_BansheePulseEnabled, meta=(AllowPrivateAccess=true))
    bool BansheePulseEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECrossbowStuckType StuckProjectileEffect;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URecallableProjectileComponent* RecallComponent;
    UCrossbowStuckProjectileEffectBanshee* BansheeComponent;
    bool IsPlayingElectricRangeEffect;
    TSubclassOf<UStatusEffect> AppliedEffect;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float StatusEffectTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* AttachmentRoot;

    UNiagaraComponent* BansheePulseComponent;
    USphereComponent* LaserCollider;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ACrossbowProjectileBase* BaseProjectile;
    ACrossbowProjectileStuck(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UsableChanged(bool CanUse);

    UFUNCTION()
    void OnRep_BansheePulseEnabled();

    void MatchParentDestroy(UHealthComponentBase* destroyed);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;
    bool GetSpecialArrowEquipped() const;
    void CollectRecallable(URecallableProjectileComponent* NewRecallComponent);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_OnCavePointRemoved(USceneComponent* Point);
};
