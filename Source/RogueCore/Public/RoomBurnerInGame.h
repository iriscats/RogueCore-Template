#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "ERunDepth.h"
#include "Templates/SubclassOf.h"
#include "RoomBurnerInGame.generated.h"

class ADeepCSGWorld;
class AProceduralSetup;
class UBiome;
class UDifficultySetting;
class UPlanetZone;
class URoomGenerator;
class URunTemplate;
class UStageTemplateDifficulty;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ARoomBurnerInGame : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool LiveUpdateEditor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URoomGenerator* RoomGenerator;
    float RoomRadius;
    bool ShowRoomCollider;
    FGameplayTagContainer RoomTags;
    ERunDepth RunDepth;
    URunTemplate* RunTemplate;
    int32 ActiveStage;
    int32 Seed;
    UBiome* Biome;
    UPlanetZone* PlanetZone;
    UStageTemplateDifficulty* DifficultyOverride;
    UDifficultySetting* Difficulty;
    int32 ForcePlayerCount;
    bool GenerateDebris;
    bool GenerateItems;
    bool GenerateResources;
    bool SpawnEncounters;
    ADeepCSGWorld* CSGWorld;
    AProceduralSetup* PLSLiveEditor;
    TSubclassOf<AProceduralSetup> CaveGeneratorPLSOverride;
 
    URoomGenerator* LiveEditRoomGenerator;
    ARoomBurnerInGame(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URoomGenerator* GetRoomGenerator() const;
};
