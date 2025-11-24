#pragma once
#include "CoreMinimal.h"
#include "Pillar.h"
#include "ResourceLocation.h"
#include "RoomBox.h"
#include "RoomEntrance.h"
#include "RoomItem.h"
#include "RoomLine.h"
#include "TriggerItem.h"
#include "GeneratedRoom.generated.h"

class UTerrainMaterial;
USTRUCT(BlueprintType)
struct FGeneratedRoom {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* Material;
    
    TArray<FRoomLine> Lines;
    TArray<FPillar> Pillars;
    TArray<FRoomBox> BoxCarvers;
    TArray<FRoomBox> BoxFillers;
    TArray<FResourceLocation> ResourceLocations;
    TArray<FRoomEntrance> Entrances;
    TArray<FRoomItem> RoomItems;
    TArray<FTriggerItem> TriggerItems;
    ROGUECORE_API FGeneratedRoom();
};
