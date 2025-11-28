#pragma once
#include "CoreMinimal.h"
#include "IntelChallenge.h"
#include "IntelChallengeNeutralizeEnemy.generated.h"

class UEnemyID;
UCLASS(Abstract, Blueprintable)
class UIntelChallengeNeutralizeEnemy : public UIntelChallenge {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyID* RequiredEnemy;
    
    int32 RequiredAmount;
    UIntelChallengeNeutralizeEnemy();
};
