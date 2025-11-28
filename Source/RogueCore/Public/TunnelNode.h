#pragma once
#include "CoreMinimal.h"

#include "RoomEntrance.h"
#include "RoomNodeBase.h"
#include "TunnelPath.h"
#include "TunnelNode.generated.h"

class UTunnelParameters;
class UTunnelSetting;
USTRUCT(BlueprintType)
struct FTunnelNode : public FRoomNodeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EntranceRoomID;
    
    int32 ExitRoomID;
    FRoomEntrance Entrance;
    FRoomEntrance Exit;
    UTunnelParameters* ParametersOverride;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTunnelPath Path;
    int32 ID;
    FVector DirtStartLocation;
    bool AddDirt;
    float WeightedResourceAmount;
    UTunnelSetting* TunnelSetting;
    ROGUECORE_API FTunnelNode();
};
