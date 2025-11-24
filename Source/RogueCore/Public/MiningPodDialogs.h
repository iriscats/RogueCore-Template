#pragma once
#include "CoreMinimal.h"
#include "MiningPodDialogs.generated.h"

class UDialogDataAsset;
USTRUCT(BlueprintType)
struct FMiningPodDialogs {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* DepartingIn5Min;
    
    UDialogDataAsset* DepartingIn4Min;
    UDialogDataAsset* DepartingIn3Min;
    UDialogDataAsset* DepartingIn2Min;
    UDialogDataAsset* DepartingIn1Min;
    UDialogDataAsset* DepartingIn30Sec;
    UDialogDataAsset* DepartingIn10Sec;
    UDialogDataAsset* DepartingIn123Sec;
    UDialogDataAsset* Departed;
    UDialogDataAsset* DeepDiveDeparted;
    ROGUECORE_API FMiningPodDialogs();
};
