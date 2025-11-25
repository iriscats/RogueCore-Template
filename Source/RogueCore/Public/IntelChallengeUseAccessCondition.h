#pragma once
#include "CoreMinimal.h"
#include "IntelChallengePlayerMonitor.h"
#include "IntelChallengeUseAccessCondition.generated.h"

class UAccessCondition;
class UUsableComponentBase;
UCLASS(Abstract, Blueprintable)
class UIntelChallengeUseAccessCondition : public UIntelChallengePlayerMonitor {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAccessCondition* RequiredAccess;
    
    int32 RequiredUseAmount;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TSet<UUsableComponentBase*> UsableComponentsUsedInThisLevel;
    UIntelChallengeUseAccessCondition();
    UFUNCTION(BlueprintCallable)
    void OnUsableTriggered(UUsableComponentBase* usable);
};
