#pragma once
#include "CoreMinimal.h"
#include "Perception/AIPerceptionTypes.h"
#include "HostileGuntowerModule.h"
#include "HostileTargetingGuntowerModule.generated.h"

class AActor;
UCLASS(Blueprintable, NoExport)
class AHostileTargetingGuntowerModule : public AHostileGuntowerModule {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))

    AActor* TargetedActor;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> SensedTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurretRotationSpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AActor* TargetedActor;
    float TargetingRotationSpeed;
    FName TargetingFromBone;
    float TimeUntilForgetTarget;
    bool AlwaysUpdateAimRotation;
    AHostileTargetingGuntowerModule(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnPerceptionUpdated(AActor* sensedActor, const FAIStimulus& Stimulus);
};
