#pragma once
#include "CoreMinimal.h"
#include "IntelChallenge.h"
#include "IntelChallengePlayerMonitor.generated.h"

class APlayerCharacter;
UCLASS(Abstract, Blueprintable)
class UIntelChallengePlayerMonitor : public UIntelChallenge {
    GENERATED_BODY()
    
 public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<APlayerCharacter*> RegisteredPlayers;

    UIntelChallengePlayerMonitor();
 
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnPlayerUnregistered(APlayerCharacter* Player);
    void BP_OnPlayerRegistered(APlayerCharacter* Player);
};
