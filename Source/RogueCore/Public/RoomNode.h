#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GeneratedRoom.h"
#include "RoomEntrance.h"
#include "RoomGeneratorItem.h"
#include "RoomNodeBase.h"
#include "RoomNode.generated.h"

USTRUCT(BlueprintType)
struct FRoomNode : public FRoomNodeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 ID;
    
    int32 CarvePass;
    FVector3f position;
    float Radius;
    TArray<int32> EntranceIDs;
    TArray<int32> ExitIDs;
    TArray<FRoomEntrance> RoomEntrances;
    bool CanHaveEnemies;
    bool CanHaveExitElevator;
    TArray<FGeneratedRoom> Rooms;
    float ResourceMultiplier;
    bool CanBeUsedForRoomBasedDistribution;
    float WeightedResourceAmount;
    TArray<FRoomGeneratorItem> RoomGenerators;
    ROGUECORE_API FRoomNode();
};
