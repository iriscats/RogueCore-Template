#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESchematicType.h"
#include "SavableDataAsset.h"
#include "SchematicCategory.generated.h"

class UDialogDataAsset;
class UEventRewardType;
class UTexture2D;
UCLASS(Blueprintable)
class USchematicCategory : public USavableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CategoryName;
    
    TSoftObjectPtr<UTexture2D> FrameTexture;
    FLinearColor FrameTint;
    FLinearColor BackgroundTint;
    ESchematicType SchematicType;
    TSoftObjectPtr<UDialogDataAsset> ShoutForging;
    UEventRewardType* RewardType;
    int32 SortOrder;
    USchematicCategory();
};
