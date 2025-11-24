#pragma once
#include "CoreMinimal.h"
#include "VanityItem.h"
#include "BeardVanityItem.generated.h"

class UMaterialInterface;
class USkeletalMesh;
class UVanityAnimInstance;
UCLASS(Blueprintable, EditInlineNew)
class UBeardVanityItem : public UVanityItem {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> mesh;

    float BeardThickness;

    bool RequiresSlimArmor;

    bool UseHairColor;

    bool UseArmorColor;

    bool HideEyebrows;

    bool HideSideburns;

    bool HideMoustache;

    bool HideAll;

    TSoftClassPtr<UVanityAnimInstance> AnimInstance;

    TSoftObjectPtr<UMaterialInterface> MaterialOverride;

public:
    UBeardVanityItem();
};
