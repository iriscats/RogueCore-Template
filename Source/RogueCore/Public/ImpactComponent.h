#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HightAccelerationSignatureDelegate.h"
#include "ImpactedSignatureDelegate.h"
#include "ImpactComponent.generated.h"

class USceneComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UImpactComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    bool DebugText;

    bool TrackAcceleration;

    bool TrackVelocity;

    float TriggerHighAccelAt;

    float TriggerAtVelocityDifference;

    UImpactComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void SetCheckVelocity(bool aCheckVelocity);



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FImpactedSignature OnImpactedEvent;
    
    FHightAccelerationSignature OnHighAcceleration;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugText;
    bool TrackAcceleration;
    bool TrackVelocity;
    float TriggerHighAccelAt;
    float TriggerAtVelocityDifference;
    UImpactComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetCheckVelocity(bool aCheckVelocity);
    void SetCheckAcceleration(bool aCheckAcceleration);
    void EnableImpactCheckhing(USceneComponent* cmp);
    void DisableImpactChecking();
};
