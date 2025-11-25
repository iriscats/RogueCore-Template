#pragma once
#include "CoreMinimal.h"
#include "EArmorMeshType.h"
#include "TattooArmorItem.h"
#include "VanityItem.h"
#include "ArmorVanityItem.generated.h"

class AFSDPlayerState;
class UAnimInstance;
class UArmorMaterialVanityItem;
class UMaterialInterface;
class USkeletalMesh;
UCLASS(Blueprintable, EditInlineNew)
class UArmorVanityItem : public UVanityItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EArmorMeshType, TSoftObjectPtr<USkeletalMesh>> TPArmorMesh;
    
    TMap<EArmorMeshType, TSoftObjectPtr<USkeletalMesh>> FPArmorMesh;
    bool AllowSleevelessUse;
    TSoftClassPtr<UAnimInstance> AnimInstance;
    bool CropBeard;
    float ArmorThickness;
    TSoftObjectPtr<UMaterialInterface> MaterialOverride;
    bool CanOnlyUseDefaultArmorMaterial;
    UArmorMaterialVanityItem* DefaultArmorMaterial;
    TArray<FTattooArmorItem> Tattoos;
    UArmorVanityItem();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void PreviewArmor(AFSDPlayerState* PlayerState, bool Show, bool useDefaultArmorMaterial) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasSleevelessArmorType() const;
};
