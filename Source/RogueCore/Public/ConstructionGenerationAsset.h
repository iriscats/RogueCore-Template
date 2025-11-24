#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ConstructionGenerationGroup.h"
#include "ConstructionItem.h"
#include "ConstructionGenerationAsset.generated.h"

UCLASS(Blueprintable)
class UConstructionGenerationAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConstructionItem> Constructions;
    
    UConstructionGenerationAsset();
    UFUNCTION(BlueprintCallable)
    FConstructionGenerationGroup CreateConstructionGroup(int32 InBudget, const FGameplayTagQuery& InQuery, UPARAM(Ref) FRandomStream& InRandomStream);
};
