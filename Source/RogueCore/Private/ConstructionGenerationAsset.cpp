#include "ConstructionGenerationAsset.h"

UConstructionGenerationAsset::UConstructionGenerationAsset() {
}

FConstructionGenerationGroup UConstructionGenerationAsset::CreateConstructionGroup(int32 InBudget, const FGameplayTagQuery& InQuery, FRandomStream& InRandomStream) {
    return FConstructionGenerationGroup{};
}


