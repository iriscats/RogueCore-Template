#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EBXECompanionDroneState.h"
#include "FSDAIController.h"
#include "Templates/SubclassOf.h"
#include "BXECompanionDroneController.generated.h"

class AActor;
class ABXECompanionDrone;
class APlayerCharacter;
class ATeamElevator;
class UBehaviorTree;
class UCompanionDroneInteractionComponent;
class UDialogDataAsset;
class UResourceData;
UCLASS(Blueprintable, NoExport)
class ABXECompanionDroneController : public AFSDAIController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ATeamElevator> ElevatorClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCompanionDroneInteractionComponent> CurrentInteractable;
    UResourceData* ArtifactResource;
    UResourceData* PotentExpeniteResource;
    UBehaviorTree* Behaviour;
    float DroneCallCooldown;
    float LandingDistance;
    float MinUpdateTargetInterval;
    float MaxUpdateTargetInterval;
    float ArtifactProcessingTime;
    float PotentExpeniteProcessingTime;
    float SaluteDelay;
    float TakeoffTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ABXECompanionDrone> drone;
    bool StoreRewards;
    UDialogDataAsset* ShoutCalling;
    TMap<EBXECompanionDroneState, UDialogDataAsset*> ShoutsWhenCannotCall;
private:
    ABXECompanionDroneController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Salute();
    void ReleaseFromMachine();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_ElevatorPressed(ATeamElevator* Elevator);
public:
    void PlayerSaluted(APlayerCharacter* ShoutingPlayer);
    void PlayerJoined(APlayerCharacter* aPlayerState);
    void OnUsed();
    void OnStoppedUsing();
    void OnResourceDeposited(UResourceData* Resource, float amount);
    void OnNegotiationStarted();
    void OnNegotiationComplete();
    void OnMessage(FName Name);
    void OnMatchStarted();
    void OnGameStateCountDownStarted(const FText& CountdownText);
    void OnGameStateCountDownEnded();
    void OnEndDeposit(APlayerCharacter* Player);
    void OnDroneLeftState(EBXECompanionDroneState State);
    void OnDroneEnterState(EBXECompanionDroneState State);
    void OnDroneCalled(FVector Location, APlayerCharacter* Player);
    void OnDeposit(APlayerCharacter* Player);
    void ElevatorUsed(ATeamElevator* Elevator);
    bool CallToMachine(AActor* Target);
};
