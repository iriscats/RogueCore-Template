#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "DamageListener.h"
#include "GlowingOrbGrowthComponent.generated.h"

class USceneComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UGlowingOrbGrowthComponent : public UActorComponent, public IDamageListener {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> GrothwMutliplierByPlayer;
    
    float DamageMultiplier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Growth, meta=(AllowPrivateAccess=true))
    float GrowthProgress;
    FRuntimeFloatCurve GrowthCurve;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> Sizer;
    UGlowingOrbGrowthComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_Growth();
    // Fix for true pure virtual functions not being implemented
};
