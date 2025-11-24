#pragma once
#include "CoreMinimal.h"
#include "TXBioboosterUpgrade.h"
#include "TXNegotiatedUnlocks.h"
#include "TXLoadout.generated.h"

USTRUCT(BlueprintType)
struct FTXLoadout {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXBioboosterUpgrade> biobooster_upgrades;
    
    TArray<FTXNegotiatedUnlocks> negotiated_unlocks;
    FString artifact_name;
    ROGUECORE_API FTXLoadout();
};
