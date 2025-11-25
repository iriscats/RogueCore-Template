#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "EncounterManagerItem.h"
#include "EncounterManager.generated.h"

class AProceduralSetup;
class UCritterDescriptor;
class UEnemyDescriptor;
class UEnemyGroupDescriptor;
class UEnemySpawnManager;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UEncounterManager : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnDistanceFromRoomBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FEncounterManagerItem> Encounters;
    AProceduralSetup* ProceduralSetup;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEnemySpawnManager* SpawnManager;
    TArray<UEnemyDescriptor*> RCEnemyPool;
    TArray<UEnemyDescriptor*> EnemyPool;
    TArray<UEnemyDescriptor*> EncounterPool;
    TArray<UCritterDescriptor*> CritterPool;
    UEncounterManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Exec)
    void ShowSpawnLocations();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UEnemyDescriptor*> GetRCEnemyPool() const;
    TArray<UEnemyDescriptor*> GetEncounterPool() const;
    TArray<UCritterDescriptor*> GetCritterPool() const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddEncounterFromGroup(UEnemyGroupDescriptor* Group, float Difficulty, FVector Location, float Radius);
};
