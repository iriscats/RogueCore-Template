#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "EnhancementReward.generated.h"

class UPerkAsset;
UCLASS(Blueprintable, EditInlineNew)
class UEnhancementReward : public UUnlockReward {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPerkAsset* Perk;

public:
    UEnhancementReward();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPerkAsset* GetPerk() const;
};
