#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkeletalMeshDecalData.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FSkeletalMeshDecalData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UTexture2D* DiffuseTex;
    UTexture2D* NormalMapTex;
    FLinearColor Color;
    FLinearColor Emissive;
    ROGUECORE_API FSkeletalMeshDecalData();
};
