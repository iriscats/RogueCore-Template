#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EMeshAttachType.h"
#include "AttachMeshesAfflictionItem.generated.h"

class UAnimSequence;
class USkeletalMesh;
class UStaticMesh;
USTRUCT(BlueprintType)
struct FAttachMeshesAfflictionItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    FRotator Rotation;
    USkeletalMesh* SkeletalMesh;
    UStaticMesh* StaticMesh;
    UAnimSequence* Animation;
    float Scale;
    FName BoneName;
    TEnumAsByte<EMeshAttachType> AttachType;
    bool LoopAnimation;
    bool RandomRotaiton;
    bool RandomScale;
    bool CastShadows;
    ROGUECORE_API FAttachMeshesAfflictionItem();
};
