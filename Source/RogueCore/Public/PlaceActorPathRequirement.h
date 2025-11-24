#pragma once
#include "CoreMinimal.h"
#include "PlaceActorPathRequirement.generated.h"

USTRUCT(BlueprintType)
struct FPlaceActorPathRequirement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequirePath;
    
    float MinimumDistance;
    float MaximumDistance;
    ROGUECORE_API FPlaceActorPathRequirement();
};
