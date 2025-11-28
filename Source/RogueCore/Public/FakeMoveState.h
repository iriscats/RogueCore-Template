#pragma once
#include "CoreMinimal.h"

#include "FakeMoveState.generated.h"

USTRUCT(BlueprintType)
struct FFakeMoveState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector Pos1 = FVector::ZeroVector;
    
    FVector Pos2;
    FVector Vel;

};
