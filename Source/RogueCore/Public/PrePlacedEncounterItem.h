#pragma once
#include "CoreMinimal.h"

#include "PrePlacedEncounterItem.generated.h"

class AEncounterActor;
class UEnemyDescriptor;
USTRUCT(BlueprintType)
struct FPrePlacedEncounterItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEnemyDescriptor* descriptor;
    
    FTransform Location;
    AEncounterActor* EncounterActor;
    int32 RoomID;
    bool IsRoomID;
    ROGUECORE_API FPrePlacedEncounterItem();
};
