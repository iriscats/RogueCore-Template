#pragma once
#include "CoreMinimal.h"
#include "EProspectorRobotState.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "ProspectorRobot.generated.h"

class AActor;
class UMaterialInstanceDynamic;
UCLASS(Blueprintable, NoExport)
class AProspectorRobot : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WorkingArmSpeed;
    
    float EnginePowerMultiplier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Target;
    float HeadResponsiveness;
    float HeadSearchSpeed;
    float HeadSearchMaxAngle;
    UMaterialInstanceDynamic* EngineMaterial;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ProspectorState, meta=(AllowPrivateAccess=true))
    EProspectorRobotState ProspectorState;
    AProspectorRobot(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetTarget(AActor* NewTarget);
    void SetArmSpeed(float Speed);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateEnd(EProspectorRobotState oldState);
    void OnStateBegin(EProspectorRobotState NewState);
    UFUNCTION()
    void OnRep_ProspectorState(EProspectorRobotState oldState);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStateActive(EProspectorRobotState State) const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ChangeState(EProspectorRobotState NewState);
};
