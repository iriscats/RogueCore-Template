#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FSDTagsRoot.h"
#include "FSDTagSettings.generated.h"

UCLASS(Blueprintable)
class UFSDTagSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery IsFriendlyQuery;
    
    FGameplayTagQuery IsNeutralQuery;
    FGameplayTagQuery IsHostileQuery;
    FFSDTagsRoot Root;
    UFSDTagSettings();
};
