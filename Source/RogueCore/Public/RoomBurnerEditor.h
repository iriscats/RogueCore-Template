#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "ERoomMirror.h"
#include "ERoomMirroringSupport.h"
#include "ERunDepth.h"
#include "RunMutatorOverrides.h"
#include "RunObjectiveOverrides.h"
#include "Templates/SubclassOf.h"
#include "RoomBurnerEditor.generated.h"

class ADebrisDataActor;
class ADeepCSGWorld;
class AProceduralSetup;
class UBiome;
class UDifficultySetting;
class UEnemyDescriptor;
class UPlanetZone;
class URoomGenerator;
class URunTemplate;
class USpecialEvent;
class UStageTemplateDifficulty;
class UStageTemplateOverride;
UCLASS(Blueprintable)
class ARoomBurnerEditor : public AActor {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool LiveUpdateEditor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERoomMirror MirrorTest;
    TSubclassOf<AProceduralSetup> OverridePLSCLass;
    URoomGenerator* RoomGenerator;
    float RoomRadius;
    ERoomMirroringSupport MirrorSupport;
    bool ShowRoomCollider;
    bool ShowLineCarvers;
    FGameplayTagContainer RoomTags;
    int32 Seed;
    ERunDepth RunDepth;
    URunTemplate* RunTemplate;
    int32 ActiveStage;
    UBiome* Biome;
    UPlanetZone* PlanetZone;
    UStageTemplateDifficulty* DifficultyOverride;
    UStageTemplateOverride* BossOverride;
    TSoftClassPtr<ADebrisDataActor> StageDebrisActor;
    UDifficultySetting* Difficulty;
    int32 ForcePlayerCount;
    bool GenerateDebris;
    bool GenerateItems;
    bool GenerateResources;
    bool SpawnEncounters;
    UEnemyDescriptor* TestEnemy;
    int32 TestEnemyCount;
    USpecialEvent* TestSpecialEvent;
    USpecialEvent* TestTreasure;
    FRunObjectiveOverrides ObjectiveOverrides;
    FRunMutatorOverrides MutatorOverrides;
    ADeepCSGWorld* CSGWorld;
    AProceduralSetup* PLSLiveEditor;
 
    URoomGenerator* LiveEditRoomGenerator;
    ARoomBurnerEditor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SpawnEncounter(AProceduralSetup* setup);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URoomGenerator* GetRoomGenerator() const;
};
