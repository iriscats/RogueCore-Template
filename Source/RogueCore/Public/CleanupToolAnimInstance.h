#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CleanupToolAnimInstance.generated.h"

class APlagueCleanupItem;
UCLASS(Blueprintable, NonTransient)
class UCleanupToolAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool isUsing;
    
 
    APlagueCleanupItem* CleaningTool;
    UCleanupToolAnimInstance();
};
