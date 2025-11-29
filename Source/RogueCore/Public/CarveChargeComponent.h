#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"

#include "BoolDelegateDelegate.h"
#include "GenericSignatureDelegate.h"
#include "CarveChargeComponent.generated.h"

class AActor;
class AEnemyDeepPathfinderCharacter;
class APawn;
class APlayerCharacter;
class UDamageAsset;
class UPrimitiveComponent;
class USceneComponent;
class USoundBase;
class USphereComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UCarveChargeComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageAsset* Damage;
    
    USoundBase* BumpSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsTelegraphing, meta=(AllowPrivateAccess=true))
    bool IsTelegraphing;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsCharging, meta=(AllowPrivateAccess=true))
    bool isCharging;
    bool IsStoppingEarly;
    USoundBase* TelegraphSound;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoolDelegate OnRepIsTelegraphing;
    FBoolDelegate OnRepIsCharging;
 
    FGenericSignature EventBeginCharge;
    FGenericSignature EventEndCharge;
    FGenericSignature EventTelegraphCharge;
    FGenericSignature EventEnterTerrain;
    FGenericSignature EventExitTerrain;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* BumpCollider;
    USceneComponent* CarveLocation;
 
    TMap<APawn*, float> BumpCooldowns;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Curve, meta=(AllowPrivateAccess=true))
    FInterpCurveVector Curve;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float CurrentSpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Target;
    float ChargeSpeed;
    float CarveRadius;
    float CarveFrequency;
    UCarveChargeComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void Unpause();
    void RamPlayer(APlayerCharacter* Player);
    void RamEnemy(AEnemyDeepPathfinderCharacter* Enemy);
    void Pause();
    UFUNCTION()
    void OnRep_IsTelegraphing();
    UFUNCTION()
    void OnRep_IsCharging();
    UFUNCTION()
    void OnRep_Curve();
    void OnBumpCollisionBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    void OnBump(AActor* OtherActor);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayBumpSound();
};
