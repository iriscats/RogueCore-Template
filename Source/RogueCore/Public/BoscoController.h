#pragma once
#include "CoreMinimal.h"

#include "GameplayTagContainer.h"
#include "EInputKeys.h"
#include "FSDAIController.h"
#include "FollowTargetChangedDelegate.h"
#include "LaserPointerTarget.h"
#include "Templates/SubclassOf.h"
#include "BoscoController.generated.h"

class AActor;
class AFSDPlayerState;
class APlayerCharacter;
class UBehaviorTree;
class UDroneUseComponent;
class UHealthComponentBase;
class UTerrainMaterial;
UCLASS(Blueprintable)
class ABoscoController : public AFSDAIController {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* BehaviourTree;
    
    float CheckOutOfTheWayInterval;
    float DistCountAsSameHit;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFollowTargetChanged OnFollowTargetChangedDelegate;
    UTerrainMaterial* HearthstoneCrystalMaterial;
    TArray<UTerrainMaterial*> PlagueMaterials;
 
    TArray<TSubclassOf<AActor>> VacuumableTypes;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> VacuumTargets;
    float SearchForEnemiesInterval;
    float SaluteDelay;
    float SaluteCooldown;
    float CheckGraberInterval;
    float MaxThrowStrength;
    float MaxThrowRange;
    float RepairRange;
    float DistanceCountedAsClose;
    FGameplayTagQuery TargetQuery;
    FGameplayTagQuery AttackOnOrderQuery;
    FGameplayTagQuery AttackOnSightQuery;
    FGameplayTagQuery DefendTageQuery;
    FGameplayTagQuery VacuumTagQuery;
    float ReviveHealthPercentage;
    float ArmorOnRevivePercentage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDroneUseComponent* CurrentUse;
    AActor* TryingToPickItem;
    ABoscoController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ReviveTarget();
    void ResetToFollowState();
 
    void RegisterPlayer(APlayerCharacter* aPlayerCharacter);
    void PickupItem();
    void OnUseDone(int32 timesUsed);
    void OnSecondaryLaserPointer(const FLaserPointerTarget& HitInfo);
    void OnPlayerShout(APlayerCharacter* aPlayerCharacter);
    void OnPlayerSalute(APlayerCharacter* aCharacater);
    void OnPlayerLeave(AFSDPlayerState* aPlayerState);
    void OnLaserPointer(const FLaserPointerTarget& HitInfo);
    void OnJobFinished();
    void OnEscortTargetDied(UHealthComponentBase* Health);
    void OnCarriedUsed(APlayerCharacter* usedBy, EInputKeys Key);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetPointNearPlayers() const;
    AActor* GetFollowTarget();
    void GenerateRelativeLocation(AActor* aTarget, float aRange, float aHeightRestriction, float aMinRange, bool aTryToStayOutOfTheWay, bool aStayBehind);
    void ConfirmPickup();
    void CarriableDrop();
};
