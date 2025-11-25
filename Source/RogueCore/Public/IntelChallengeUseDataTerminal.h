#pragma once
#include "CoreMinimal.h"
#include "ERunDepth.h"
#include "IntelChallengePlayerMonitor.h"
#include "IntelChallengeUseDataTerminal.generated.h"

class AActor;
UCLASS(Abstract, Blueprintable)
class UIntelChallengeUseDataTerminal : public UIntelChallengePlayerMonitor {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredUseAmount;
    
    ERunDepth RequiredRunDepth;
    bool RequireMutator;
    UIntelChallengeUseDataTerminal();
 
    UFUNCTION(BlueprintCallable)
    void OnActivatedTerminal(AActor* TerminalActor);
};
