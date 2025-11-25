#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"

#include "Curves/CurveFloat.h"
#include "ChangeVacuumStateDelegateDelegate.h"
#include "EVacuumState.h"
#include "Templates/SubclassOf.h"
#include "FoamPuddle.generated.h"

class UNiagaraComponent;
class UPrimitiveComponent;
class USceneComponent;
class USoundCue;
UCLASS(Blueprintable)
class AFoamPuddle : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USceneComponent* PuddleRoot;
    UNiagaraComponent* NS_Foam;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve ScaleCurve;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChangeVacuumStateDelegate OnChangeVacuumStateDelegate;
    TArray<TSubclassOf<AActor>> VacuumableActors;
    USoundCue* PickupSound;
    float PickupSoundCooldown;
    USoundCue* PickupFilledSound;
    float PickupFilledCooldown;
    USoundCue* VacuumedSound;
    float VacuumedCooldown;
    USoundCue* VacuumedSoundFilled;
    float VacuumedSoundFilledCooldown;
    float InitialDebrisRadius;
    float TotalRadiusGrowth;
    float GrowthTime;
    float AttractorPowerWhenVacuuming;
    float ScaleTimeVacuuming;
    float Speed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EVacuumState State;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Replicated, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* VacuumSource;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint16 MaxSoapPiles;
    bool UsesLocalSpace;
    AFoamPuddle(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetState(EVacuumState NewState);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void SetPuddleLifetime(float Lifetime);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ScaleOutAndDestroy();
    UFUNCTION()
    void OnRep_State(EVacuumState prevState);
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
