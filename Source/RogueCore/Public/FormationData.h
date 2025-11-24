#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FormationDataItem.h"
#include "FormationData.generated.h"

UCLASS(Abstract, Blueprintable)
class UFormationData : public UDataAsset {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFormationDataItem> FormationItems;

    FGameplayTagQuery LeaderQuery;

    FGameplayTagQuery MemberQuery;

public:
    UFormationData();
};
