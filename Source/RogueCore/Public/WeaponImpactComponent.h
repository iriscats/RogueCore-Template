#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HightAccelerationSignatureDelegate.h"
#include "ImpactedSignatureDelegate.h"
#include "WeaponImpactComponent.generated.h"

class USkeletalMeshComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWeaponImpactComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FImpactedSignature OnImpactedEvent;
    
    FHightAccelerationSignature OnHighAcceleration;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugText;
    FName ImpactSocketName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* ActiveMesh;
    bool TrackAcceleration;
    bool TrackVelocity;
    float TriggerHighAccelAt;
    float TriggerAtVelocityDifference;
    UWeaponImpactComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void EnableImpactCheckhing(USkeletalMeshComponent* cmp);
    void DisableImpactChecking();
};
