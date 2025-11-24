#pragma once
#include "CoreMinimal.h"
#include "EnhancementSettings.generated.h"

USTRUCT(BlueprintType)
struct FEnhancementSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> SlotUnlockLevel;
    
    ROGUECORE_API FEnhancementSettings();
};
