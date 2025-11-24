#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ExcavationReward.generated.h"

class AActor;
class UDialogDataAsset;
class UTexture2D;
USTRUCT(BlueprintType)
struct FExcavationReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Title;
    
    TSoftObjectPtr<UTexture2D> Image;
    TSubclassOf<AActor> RewardClass;
    TSoftObjectPtr<UDialogDataAsset> OmegaShoutOnSelected;
    float PercentChance;
    bool ShouldBeRemovedAfterPick;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ResourceAmount;
    ROGUECORE_API FExcavationReward();
};
