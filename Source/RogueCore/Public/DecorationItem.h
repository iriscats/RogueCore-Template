#pragma once
#include "CoreMinimal.h"
#include "DecorationItem.generated.h"

class AActor;
class UDebrisPositioning;
USTRUCT(BlueprintType)
struct FDecorationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> Decoration;
    
    int32 MinSpawnAmount;
    int32 MaxSpawnAmount;
    UDebrisPositioning* Positioning;
    ROGUECORE_API FDecorationItem();
};
