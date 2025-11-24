#pragma once
#include "CoreMinimal.h"
#include "Perception/AIPerceptionTypes.h"
#include "FSDAIController.h"
#include "FacilityTurretController.generated.h"

class AActor;
class UAIPerceptionComponent;
class UHealthComponentBase;
UCLASS(Blueprintable, NoExport)
class AFacilityTurretController : public AFSDAIController {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    float RememberTargetTime;

    float RetargetOnAttackChance;

    bool RespectAttack;

    AFacilityTurretController(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIPerceptionComponent* Perception;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RememberTargetTime;
    float RetargetOnAttackChance;
    bool RespectAttack;
    AFacilityTurretController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnTurretsAttackingChanged(bool IsAttacking);
    void OnTargetRevived();
    void OnTargetDied(UHealthComponentBase* Health);
    void OnPerceptionUpdated(AActor* sensedActor, FAIStimulus Stimulus);
};
