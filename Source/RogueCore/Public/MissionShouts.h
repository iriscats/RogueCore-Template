#pragma once
#include "CoreMinimal.h"
#include "MissionShouts.generated.h"

class UDialogDataAsset;
USTRUCT(BlueprintType)
struct FMissionShouts {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* AfterDropPodExit;
    
    UDialogDataAsset* OnExitPodDescending;
    UDialogDataAsset* OnExitPodArrived;
    UDialogDataAsset* OnCompletion;
    UDialogDataAsset* OnCompletion_OneOfMultiple;
    UDialogDataAsset* OnAllReturnObjectivesCompleted;
    UDialogDataAsset* OnDeepDiveExitPodDescending;
    ROGUECORE_API FMissionShouts();
};
