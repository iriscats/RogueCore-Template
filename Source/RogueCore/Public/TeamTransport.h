#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "EMiningPodMission.h"
#include "EMiningPodRampState.h"
#include "EMiningPodState.h"
#include "Templates/SubclassOf.h"
#include "TeamTransport.generated.h"

class AMolly;
class ATeamTransport;
class UBoxComponent;
class UCurveFloat;
class UObject;
class UObjectivesManager;
class UOutlineComponent;
UCLASS(Blueprintable)
class ROGUECORE_API ATeamTransport : public AActor, public IGameplayTagAssetInterface {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DropHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;
 
    UCurveFloat* DropCurve;
    UCurveFloat* ArriveCurve;
    UCurveFloat* DepartCurve;
    FGameplayTagContainer GameplayTags;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* DwarfCheckerBox;
    float DepartureTime;
    FText DepartueCountdownName;
    EMiningPodMission MissionType;
    bool WaitForPlayerSpawns;
    bool RequireAllPlayersInTransport;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool HasLanded;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UOutlineComponent* PodOutline;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FVector StartLocation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EMiningPodState TransportState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_RampState, meta=(AllowPrivateAccess=true))
    EMiningPodRampState rampState;
    bool isEscapeTransport;
    float TargetDropTime;
    float TargetDepartureTime;
    float TimeToDrop;
    UObjectivesManager* ObjectivesManager;
    ATeamTransport(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ATeamTransport* SpawnPodAtLocation(UObject* WorldContextObject, TSubclassOf<ATeamTransport> podClass, const FTransform& Transform, bool inIsEscapeTransport);
    UFUNCTION(BlueprintCallable)
    void SetTransportLocation(const FVector& InLocation);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetRampState(EMiningPodRampState NewRampState);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMuleInstance(AMolly* Donkey);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void RecieveReturnTimerFifteenSecondWarning();
    void RecieveReturnTimerExpired();
    void PrepForTakeOff();
    void PowerUp();
    void PoweredUp();
    UFUNCTION()
    void OnRep_State();
    UFUNCTION()
    void OnRep_RampState();
    void OnPrepForTakeOff();
    void OnPoweringUp();
    void OnPoweredUp();
    void OnHostInsidePod(bool isInside);
    void OnDropStarted();
    void OnDroppodImpact();
    void OnDrillingStarted();
    void OnDeparting();
    void OnCountdownFinished();
    void OnCountdownChanged(int32 NewTime);
    void OnAllDwavesInsidePod(bool AllInside);
    FVector GetTransportLocation() const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTimeToDeparture() const;
    bool GetHasLanded() const;
    void ForceTakeoff();
    void ExitSpacerig();
    static void DropToTarget(UObject* WorldContextObject, TSubclassOf<ATeamTransport> podClass, const FTransform& dropLocation, int32 DropDelay);
    static ATeamTransport* DropToMission(UObject* WorldContextObject, TSubclassOf<ATeamTransport> podClass, const FVector& Location);
    void DepositAllPlayersMaterials();
    void Depart();
    void CorrectLocationsForSpawnedOnLocation();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObjet"))
    static FVector AdjustLandingLocationToGround(UObject* WorldContextObjet, const FVector& initialLocation, float maxDownAdjustment, bool canAdjustUpwards);
    // Fix for true pure virtual functions not being implemented
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override PURE_VIRTUAL(HasMatchingGameplayTag, return false;);
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAnyMatchingGameplayTags, return false;);
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAllMatchingGameplayTags, return false;);
    void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(GetOwnedGameplayTags, ;);
    FGameplayTagContainer BP_GetOwnedGameplayTags() const override PURE_VIRTUAL(BP_GetOwnedGameplayTags, return FGameplayTagContainer{};);
};

