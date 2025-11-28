#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "DebrisCellNoise.generated.h"

UCLASS(Blueprintable)
class UDebrisCellNoise : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    FVector CellSize;
    int32 NumValues;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector InvCellSize;
    bool Initialized;
    UDebrisCellNoise();
};
