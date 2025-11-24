#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "EnemyRarityMutator.generated.h"

class UEnemyDescriptor;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UEnemyRarityMutator : public UMutator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RarityMultiplier;
    
    float SpawnAmountMultiplier;
    float DifficultyMultiplier;
    UEnemyDescriptor* EnemyDescriptor;
    UEnemyRarityMutator();
};
