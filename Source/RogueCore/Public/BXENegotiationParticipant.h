#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockInstance.h"
#include "ItemSlotIndex.h"
#include "BXENegotiationParticipant.generated.h"

class AFSDPlayerState;
USTRUCT(BlueprintType)
struct FBXENegotiationParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AFSDPlayerState> PlayerState;
    
    int32 SelectedIndex;
    int32 RequestedIndex;
    FItemSlotIndex SelectedSlot;
    FBXEUnlockInstance SelectedUnlock;
    int32 SelectedDroneUnlockIndex;
    ROGUECORE_API FBXENegotiationParticipant();
};
