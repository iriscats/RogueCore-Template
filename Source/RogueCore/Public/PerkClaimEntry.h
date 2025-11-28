#pragma once
#include "CoreMinimal.h"

#include "PerkClaimEntry.generated.h"

USTRUCT(BlueprintType)
struct FPerkClaimEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid PerkID;
    
    ROGUECORE_API FPerkClaimEntry();
};
