#pragma once
#include "CoreMinimal.h"
#include "EMissionControlID.h"
#include "MissionShoutQueueItem.generated.h"

class USoundBase;
USTRUCT(BlueprintType)
struct FMissionShoutQueueItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> AudioPtr;
    
    FText Text;
    USoundBase* LoadedAudio;
    EMissionControlID ControllerId;
    ROGUECORE_API FMissionShoutQueueItem();
};
