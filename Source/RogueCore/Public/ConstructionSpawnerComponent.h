#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ConstructionGenerationGroup.h"
#include "DecorationItem.h"
#include "DirtDecorationItem.h"
#include "ConstructionSpawnerComponent.generated.h"

class UObject;
class UPostConstructionSpawnDataAsset;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UConstructionSpawnerComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPostConstructionSpawnDataAsset* PostConstructionSpawnDataAsset;
    
    TArray<FDecorationItem> Decoration;
    TArray<FDirtDecorationItem> DirtDecoration;
    bool LogSpawning;
    bool PrintSpawning;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> LevelPersistentEditorAssets;
    UConstructionSpawnerComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void AddConstructionGroupToRoom(int32 InRoomID, FConstructionGenerationGroup InGroup);
};
