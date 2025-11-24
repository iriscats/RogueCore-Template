#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DisplayContent.generated.h"

class UAnimationAsset;
class USkeletalMesh;
USTRUCT(BlueprintType)
struct FDisplayContent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* Idle;
    
    UAnimationAsset* React;
    USkeletalMesh* mesh;
    FVector PivotOffset;
    FRotator RotationOffset;
    FVector Scale;
    TArray<FText> Description;
    ROGUECORE_API FDisplayContent();
};
