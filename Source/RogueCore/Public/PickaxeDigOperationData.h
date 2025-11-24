#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PickaxeDigOperationData.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FPickaxeDigOperationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OperationNumber;
    
    FVector3f HitPos;
    FVector3f Dir;
    float DigSize;
    AActor* Miner;
    ROGUECORE_API FPickaxeDigOperationData();
};
