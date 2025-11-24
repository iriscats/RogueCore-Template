#pragma once
#include "CoreMinimal.h"
#include "IntelChallenge.h"
#include "IntelChallengeNeutralizeEnemy.generated.h"

class UEnemyID;
UCLASS(Abstract, Blueprintable)
class UIntelChallengeNeutralizeEnemy : public UIntelChallenge {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyID* RequiredEnemy;
    
    int32 RequiredAmount;
    UIntelChallengeNeutralizeEnemy();
};
