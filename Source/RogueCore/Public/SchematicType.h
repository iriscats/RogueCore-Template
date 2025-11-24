#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SchematicType.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FSchematicType {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Icon;
    
    FLinearColor IconTint;
    TSoftObjectPtr<UTexture2D> Frame;
    FLinearColor FrameTint;
    ROGUECORE_API FSchematicType();
};
