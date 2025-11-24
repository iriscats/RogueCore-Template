#pragma once
#include "CoreMinimal.h"
#include "PerkState.generated.h"

class UPerkAsset;
USTRUCT(BlueprintType)
struct FPerkState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPerkAsset* Perk;
    
    bool IsBlocked;
    int32 UseCount;
    int32 MaxUses;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NotReplicated, meta=(AllowPrivateAccess=true))
    float LastUseTime;
    float CoolDown;
    ROGUECORE_API FPerkState();
};
