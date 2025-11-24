#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BasicColor.h"
#include "BasicMaterialParameters.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct BASICUI_API FBasicMaterialParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FVector4> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FBasicColor> Colors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UTexture2D*> Textures;
    
    FBasicMaterialParameters();
};

