#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ZipLine.generated.h"

USTRUCT(BlueprintType)
struct FZipLine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Start = FVector::ZeroVector;
    
    FVector End;

};
