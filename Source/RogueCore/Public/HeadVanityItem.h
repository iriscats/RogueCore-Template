#pragma once
#include "CoreMinimal.h"
#include "ECharacterHeadMesh.h"
#include "EHeadVanityType.h"
#include "VanityItem.h"
#include "HeadVanityItem.generated.h"

class UArmorVanityItem;
class UMaterialInterface;
class UPlayerCharacterID;
class USkeletalMesh;
class UVanityAnimInstance;
UCLASS(Blueprintable, EditInlineNew)
class UHeadVanityItem : public UVanityItem {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> mesh;
    
    TSoftClassPtr<UVanityAnimInstance> AnimInstance;
    EHeadVanityType HeadVanityType;
    bool HideEyebrows;
    bool HideSideburns;
    bool HideMoustache;
    bool HideBeard;
    bool HideAll;
    bool RequiresSlimArmor;
    TArray<UArmorVanityItem*> ForceThickAmorsHack;
    bool HideHead;
    ECharacterHeadMesh HeadMesh;
    TSoftObjectPtr<UMaterialInterface> MaterialOverride;
    TMap<UPlayerCharacterID*, TSoftObjectPtr<UMaterialInterface>> ClassMaterials;
    UHeadVanityItem();
};
