#pragma once
#include "CoreMinimal.h"
#include "SavableDataAsset.h"
#include "StageDuration.generated.h"

UCLASS(Blueprintable)
class UStageDuration : public USavableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    float HazardBonus;
    int32 NumberOfDots;
    bool IsUnlockedFromStart;
    UStageDuration();
};
