#pragma once
#include "CoreMinimal.h"

#include "EGeneratorIconType.h"
#include "EPickaxePartLocation.h"
#include "PickaxeSet.h"
#include "GenerateIconInfo.generated.h"

class UItemSkin;
class UPickaxePart;
class UPlayerCharacterID;
class UVanityItem;
USTRUCT(BlueprintType)
struct FGenerateIconInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EGeneratorIconType IconType;
    
    UPickaxePart* PickaxePart;
    FPickaxeSet PickaxeSet;
    EPickaxePartLocation PickaxePartLocation;
    UItemSkin* ItemSkin;
    UVanityItem* Item;
    UPlayerCharacterID* Character;
    FVector2D Size;
    bool bShowCloseUp;
    ROGUECORE_API FGenerateIconInfo();
};
