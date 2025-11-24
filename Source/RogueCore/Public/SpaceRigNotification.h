#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpaceRigNotification.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FSpaceRigNotification {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    
    UTexture2D* Icon;
    FLinearColor IconColor;
    ROGUECORE_API FSpaceRigNotification();
};
