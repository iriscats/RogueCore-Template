#pragma once
#include "CoreMinimal.h"
#include "BaseCritterDescriptor.h"
#include "RareCritterDescriptor.generated.h"

UCLASS(Blueprintable)
class URareCritterDescriptor : public UBaseCritterDescriptor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Rarity;
    
    URareCritterDescriptor();
};
