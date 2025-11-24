#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/LatentActionManager.h"
#include "EPickaxePartLocation.h"
#include "EVanitySlot.h"
#include "GenerateIconInfo.h"
#include "PickaxeSet.h"
#include "IconGenerationManager.generated.h"

class AIconGenerationBase;
class AIconGenerationCharacter;
class AIconGenerationPickaxe;
class AIconGenerationWeapon;
class UIconGenerationManager;
class UItemSkin;
class UPickaxePart;
class UPlayerCharacterID;
class UTextureRenderTarget2D;
class UVanityItem;
UCLASS(Blueprintable)
class UIconGenerationManager : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AIconGenerationCharacter* GeneratorInst;
    
    AIconGenerationPickaxe* PickaxeGeneratorInst;
    AIconGenerationWeapon* WeaponGeneratorInst;
    TArray<FGenerateIconInfo> ItemGenerationQueue;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EVanitySlot> VanitySlots;
    TArray<UVanityItem*> HairColorHairItems;
    TSoftClassPtr<AIconGenerationCharacter> IconCharacter;
    TSoftClassPtr<AIconGenerationPickaxe> IconPickaxe;
    TSoftClassPtr<AIconGenerationWeapon> IconWeapon;
    UTextureRenderTarget2D* LatestGeneratedTexture;
    AIconGenerationBase* ActiveIconGenerator;
    UIconGenerationManager();
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    static void GenerateWeaponIcon_Async(UIconGenerationManager* manager, UItemSkin* Item, bool inShowCloseUp, UPlayerCharacterID* Character, UTextureRenderTarget2D*& Icon, FLatentActionInfo LatentInfo);
    static void GenerateVanityIcon_Async(UIconGenerationManager* manager, UVanityItem* Item, UPlayerCharacterID* Character, UTextureRenderTarget2D*& Icon, FLatentActionInfo LatentInfo);
    static void GeneratePickaxeSetIcon_Async(UIconGenerationManager* manager, FPickaxeSet PickaxeSet, UPlayerCharacterID* Character, UTextureRenderTarget2D*& Icon, FLatentActionInfo LatentInfo);
    static void GeneratePickaxePartIcon_Async(UIconGenerationManager* manager, UPickaxePart* part, EPickaxePartLocation PickaxePartLocation, UPlayerCharacterID* Character, UTextureRenderTarget2D*& Icon, FLatentActionInfo LatentInfo);
};
