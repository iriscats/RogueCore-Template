#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "RarityWeightItem.h"
#include "NegotiationRarityModifierMutator.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UNegotiationRarityModifierMutator : public UMutator {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRarityWeightItem> RarityLevelItems;
    
    UNegotiationRarityModifierMutator();
};
