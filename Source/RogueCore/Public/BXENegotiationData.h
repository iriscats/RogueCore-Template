#pragma once
#include "CoreMinimal.h"
#include "BXENegotiationParticipant.h"
#include "BXEUnlockInstance.h"
#include "BXENegotiationData.generated.h"

class AFSDPlayerState;
class UBXEUnlockBase;
USTRUCT(BlueprintType)
struct FBXENegotiationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNegotiating;
    
    TArray<FBXEUnlockInstance> Unlocks;
    TArray<FBXEUnlockInstance> DroneUnlocks;
    UBXEUnlockBase* SkipUnlock;
    TArray<FBXENegotiationParticipant> Participants;
    int32 ActiveParticipant;
    int32 Timeout;
    int32 Level;
    FString TelemetryIdentifier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AFSDPlayerState> PausedByPlayer;
    ROGUECORE_API FBXENegotiationData();
};
