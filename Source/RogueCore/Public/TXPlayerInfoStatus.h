#pragma once
#include "CoreMinimal.h"
#include "TXPlayerEnhancement.h"
#include "TXPlayerInfoStatus.generated.h"

USTRUCT(BlueprintType)
struct FTXPlayerInfoStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 player_rank;
    
    FString played_class;
    int32 class_level;
    bool is_host;
    TArray<FTXPlayerEnhancement> equipped_enhancements;
    ROGUECORE_API FTXPlayerInfoStatus();
};
