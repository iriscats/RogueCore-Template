#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PerkDelegateItem.generated.h"

class UPerkAsset;
UCLASS(Blueprintable)
class ROGUECORE_API UPerkDelegateItem : public UObject {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPerkIntDelegate, UPerkAsset*, Perk, int32, Value);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPerkHighlightedDelegate, UPerkAsset*, Perk, bool, IsHighlighted);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPerkClaimedDelegate, UPerkAsset*, Perk, int32, ClaimedTier);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerkClaimedDelegate OnPerkClaimed;
    FPerkHighlightedDelegate OnPerkHighlighted;
    FPerkIntDelegate OnChargesUsedChanged;
    UPerkDelegateItem();
};
