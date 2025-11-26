#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CoreTentacleSwayTarget.generated.h"

USTRUCT(BlueprintType)
struct FCoreTentacleSwayTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector MoveTo = FVector::ZeroVector;
    
    FVector LookAt;

};
