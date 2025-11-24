#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ESchematicType.h"
#include "ForginSettings.generated.h"

UCLASS(Blueprintable)
class UForginSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 XPRequiredPerLevel;
    
    TArray<ESchematicType> MasteryRewardCycle;
    UForginSettings();
};
