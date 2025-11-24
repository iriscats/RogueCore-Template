#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnemyGroupDescriptorItem.h"
#include "RandInterval.h"
#include "EnemyGroupDescriptor.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UEnemyGroupDescriptor : public UDataAsset {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemyGroupDescriptorItem> Enemies;

    bool UseCustomDiversity;

    FRandInterval Diversity;

public:
    UEnemyGroupDescriptor();
};
