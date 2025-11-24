#pragma once
#include "CoreMinimal.h"
#include "SimpleObjectInfoData.generated.h"

class UDialogDataAsset;
class UTexture2D;
USTRUCT(BlueprintType)
struct FSimpleObjectInfoData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText InGameName;
    
    FText InGameDescription;
    UDialogDataAsset* LookAtShout;
    UTexture2D* Icon;
    ROGUECORE_API FSimpleObjectInfoData();
};
