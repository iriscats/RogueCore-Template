#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoilGunTrailSegment.generated.h"

UCLASS(Blueprintable, NoExport)
class ACoilGunTrailSegment : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EffectsLife, meta=(AllowPrivateAccess=true))
    float EffectsLife;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeactivationTime;
    ACoilGunTrailSegment(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartEffects();
    UFUNCTION(BlueprintCallable)
    void OnRep_EffectsLife();
    void OnEndEffects();
};
