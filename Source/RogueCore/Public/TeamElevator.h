#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ETeamElevatorType.h"
#include "ElevatorDelegateDelegate.h"
#include "TeamTransport.h"
#include "Templates/SubclassOf.h"
#include "TeamElevator.generated.h"

class AActor;
class AGeneratorLine;
class AProceduralSetup;
class UDebrisPositioning;
class UElevatorGearsAnimInstance;
class URiskVector;
class USceneComponent;
class UStage;
UCLASS(Blueprintable, NoExport)
class ATeamElevator : public ATeamTransport {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FElevatorDelegate OnElevatorPoweredUp;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AGeneratorLine* ElevatorCableInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* MovingPlatformRoot;
    UElevatorGearsAnimInstance* GearsAnimInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGeneratorLine> ElevatorCableClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStage* NextStage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRepNextLevelName, meta=(AllowPrivateAccess=true))
    FText NextLevelName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRepNextLevelWarnings, meta=(AllowPrivateAccess=true))
    TArray<URiskVector*> NextLevelRiskVectors;
    ETeamElevatorType Type;
    ATeamElevator(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    static void SpawnSubElevatorCable(TSubclassOf<AGeneratorLine> InCableClass, const TArray<ATeamTransport*>& InTeamElevators, const TArray<FTransform>& InEnds);
    void SpawnElevatorCable(const FTransform& Start, const TArray<FTransform>& End);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Receive_SetIsMoving(bool Moving);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRepNextLevelWarnings();
    UFUNCTION()

    void OnRepNextLevelName();
    void InitializeNextLevel(const int32 NextStageIndex);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETeamElevatorType GetType() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    UElevatorGearsAnimInstance* GetGearsAnimInstance() const;
    AGeneratorLine* GetElevatorCableInstance() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FVector GetBottomLocation() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    TArray<FTransform> GetAllElevatorCableStartPoints() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    TArray<FTransform> GetAllElevatorCableEndPoints() const;
    static FTransform FindTeamElevatorSpawnTransform(AProceduralSetup* setup, UDebrisPositioning* DebrisPositioning, TSubclassOf<AActor> terrainPlacement, bool AllowInvalidRoomsAsFallback, float blockDistFromLandingZone, const bool rotateFacingLastTunnel);
};
