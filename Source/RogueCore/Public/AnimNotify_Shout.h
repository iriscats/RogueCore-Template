#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_Shout.generated.h"

class UDialogDataAsset;
UCLASS(Blueprintable, CollapseCategories, MinimalAPI)
class UAnimNotify_Shout : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* Shout;
    
    bool ShoutNetworked;
    float LocalShoutVolumeMultiplier;
    UAnimNotify_Shout();
};
