#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "MeleeSwipeHitData.h"
#include "MeleeSwipeData.generated.h"

class AActor;
class UFSDPhysicalMaterial;
USTRUCT(BlueprintType)
struct FMeleeSwipeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMeleeSwipeHitData> HitData;
    
    TArray<AActor*> ActorList;
    TArray<UFSDPhysicalMaterial*> MaterialList;
    FVector_NetQuantize Location;
    FVector_NetQuantizeNormal Direction;
    ROGUECORE_API FMeleeSwipeData();
};
