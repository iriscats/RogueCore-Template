#pragma once
#include "CoreMinimal.h"
#include "VanityItem.h"
#include "MoustacheVanityItem.generated.h"

class USkeletalMesh;
class UVanityAnimInstance;
UCLASS(Blueprintable, EditInlineNew)
class UMoustacheVanityItem : public UVanityItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> mesh;
    
    TSoftClassPtr<UVanityAnimInstance> AnimInstance;
    bool RequiresSlimArmor;
    UMoustacheVanityItem();
};
