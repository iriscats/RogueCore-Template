#pragma once
#include "CoreMinimal.h"
#include "ParsedActorDamageCollection.h"
#include "ParsedCharacterDamageData.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FParsedCharacterDamageData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FParsedActorDamageCollection> EnemyDamage;
    
    TArray<FParsedActorDamageCollection> PlayerDamage;
    int32 PlayerIndex;
    FParsedCharacterDamageData();
};
