#pragma once
#include "CoreMinimal.h"
#include "IntelChallenge.h"
#include "IntelChallengePlayerMonitor.generated.h"

class APlayerCharacter;
UCLASS(Abstract, Blueprintable)
class UIntelChallengePlayerMonitor : public UIntelChallenge {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<APlayerCharacter*> RegisteredPlayers;

    UIntelChallengePlayerMonitor();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnPlayerUnregistered(APlayerCharacter* Player);
    void BP_OnPlayerRegistered(APlayerCharacter* Player);
};
