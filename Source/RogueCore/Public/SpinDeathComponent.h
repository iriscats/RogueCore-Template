#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageData.h"
#include "DelegateDelegate.h"
#include "SpinDeathComponent.generated.h"

class ADeepPathfinderCharacter;
class UDamageTag;
class UHealthComponent;
class UMeshComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USpinDeathComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnCrashLanding;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMeshComponent* MeshToMove;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeathSpinTime;
    float DeathRotationSpeed;
    float NewPointMax;
    float NewPointMin;
    float DeathSpeed;
    float DeathAcceleration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ADeepPathfinderCharacter* Owner_DeepPathfinder;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_HasDied, meta=(AllowPrivateAccess=true))
    bool HasDied;
    USpinDeathComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetMeshToMove(UMeshComponent* InMesh);
    UFUNCTION()
    void OnRep_HasDied();
    void OnOwnerDeath(UHealthComponent* HealthComponent, float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& Tags);
};
