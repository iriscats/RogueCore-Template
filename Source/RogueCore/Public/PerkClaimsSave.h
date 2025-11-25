#pragma once
#include "CoreMinimal.h"
#include "PerkClaimEntry.h"
#include "PerkClaimsSave.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FPerkClaimsSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPerkClaimEntry> PerkEntries;
    FPerkClaimsSave();
 
};
