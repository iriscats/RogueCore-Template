#pragma once
#include "CoreMinimal.h"
#include "TXMinimalContentEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXMinimalContentEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString remove_me;
    
    ROGUECORE_API FTXMinimalContentEvent();
};
