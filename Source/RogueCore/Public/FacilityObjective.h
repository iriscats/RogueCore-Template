#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemySpawnedDelegateDelegate.h"
#include "IRandRange.h"
#include "Objective.h"
#include "RandInterval.h"
#include "RoomNode.h"
#include "SubObjective.h"
#include "Templates/SubclassOf.h"
#include "FacilityObjective.generated.h"

class AActor;
class APawn;
class AProceduralSetup;
class ARessuplyPod;
class ATetherStation;
class UCappedResource;
class UDebrisPositioning;
class UEncounterManager;
class UEnemyDescriptor;
class UResourceData;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UFacilityObjective : public UObjective {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    TArray<APawn*> spawnedEnemies;

    TArray<UEnemyDescriptor*> TurretDescriptors;

    TArray<UEnemyDescriptor*> GeneratorRoomTurretDescriptors;

    TArray<UEnemyDescriptor*> EncounterEnemies;

    float EncounterDifficulty;

    FRandInterval Diversity;

    FIRandRange TurretEncountersRange;

    int32 MinimumTurretEncounters;

    FIRandRange TunnelTurretsRange;

    TArray<AActor*> SmallGenerators;

    ATetherStation* mainFacility;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_GeneratorsActivated, meta=(AllowPrivateAccess=true))

    int32 GeneratorsActivated;

    UFacilityObjective(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ARessuplyPod> generatorClass;
    
    TSoftClassPtr<AActor> GeneratorBeaconClass;
    int32 GeneratorCount;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ObjectivesStage, meta=(AllowPrivateAccess=true))
    int32 ObjectivesStage;
    TArray<FSubObjective> SubObjectives;
    FEnemySpawnedDelegate OnFirstEncounterDroneSpawned_Delegate;
    FEnemySpawnedDelegate OnSecondEncounterDroneSpawned_Delegate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<APawn*> spawnedEnemies;
    TArray<UEnemyDescriptor*> TurretDescriptors;
    TArray<UEnemyDescriptor*> GeneratorRoomTurretDescriptors;
    TArray<UEnemyDescriptor*> EncounterEnemies;
    float EncounterDifficulty;
    FRandInterval Diversity;
    FIRandRange TurretEncountersRange;
    int32 MinimumTurretEncounters;
    FIRandRange TunnelTurretsRange;
    TArray<AActor*> SmallGenerators;
    ATetherStation* mainFacility;
    TArray<int32> ShieldGeneratorRooms;
    int32 MainFacilityRoom;
    bool HasRemovedMainShield;
    TArray<AActor*> ShieldGenerators;
    UResourceData* GoalResource;
    float AmountRequired;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_AmountCollected, meta=(AllowPrivateAccess=true))
    float AmountCollected;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_GeneratorsActivated, meta=(AllowPrivateAccess=true))
    int32 GeneratorsActivated;
    UFacilityObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SpawnFacilityEncounters(AProceduralSetup* setup, UEncounterManager* Encounters, UDebrisPositioning* Positioning);
    TArray<FTransform> SpawnEndBattleTurrets(int32 amountOfTurrets, AProceduralSetup* setup, UDebrisPositioning* DebrisPositioning, TSubclassOf<AActor> terrainPlacement, const TArray<AActor*>& existingTurrets, bool& success);
    void SetMainFacility(ATetherStation* NewMainFacility);
    void SetGeneratorRooms(TArray<int32>& generatorRoomsIndicies);
    void SecondGeneratorEncounterSpawn(APawn* spawned);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_AddEnemies(AProceduralSetup* setup);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ProgressCurrentObjective();
    AActor* PlaceObjectInRoom(AProceduralSetup* setup, const FRoomNode& RoomNode, UDebrisPositioning* Positioning, TSubclassOf<AActor> placementActor, FRandomStream RandomStream, const bool checkImportantLocations);
    void OnResourceChanged(UCappedResource* Resource, float amount);
    UFUNCTION()
    void OnRep_ObjectivesStage();
    UFUNCTION()
    void OnRep_GeneratorsActivated();
    UFUNCTION()
    void OnRep_AmountCollected();
    void OnCoreDeposited();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSubObjectiveComplete(int32 objectiveIndex) const;
    void InitGeneratorCount(int32 Generators);
    FTransform GetTurretGoal(AProceduralSetup* setup, const FVector& Origin, float idealRange, UDebrisPositioning* DebrisPositioning, TSubclassOf<AActor> terrainPlacement, bool& success);
    TArray<AActor*> GetShieldGenerators();
    int32 GetShieldGeneratorCount() const;
    void GetObjectTransformInRoom(FTransform& Transform, AProceduralSetup* setup, const FRoomNode& RoomNode, UDebrisPositioning* Positioning, TSubclassOf<AActor> placementActor, FRandomStream RandomStream, const bool checkImportantLocations);
    int32 GetFacilityRoomIndex() const;
    FVector GetFacilityLocation() const;
    FSubObjective GetCurrentObjective() const;
    void GeneratorActivated();
    void FirstGeneratorEncounterSpawn(APawn* spawned);
    void DropOverCharger(AProceduralSetup* setup, int32 roomIndex, const FVector& facilityLocation, float idealRange, float idealZDistance, UDebrisPositioning* DebrisPositioning, TSubclassOf<ARessuplyPod> NewGeneratorClass);
    void ChangeObjective();
    void AddShieldGenerator(AActor* charger, int32 roomIndex);
};
