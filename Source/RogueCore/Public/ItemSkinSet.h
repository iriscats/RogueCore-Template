#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemSkinSet.generated.h"

class UDynamicIcon;
UCLASS(Blueprintable)
class ROGUECORE_API UItemSkinSet : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ColorIsLockedToSet;
    
    FText SkinName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDynamicIcon* PaintJobDynamicIcon;
    UDynamicIcon* FrameworkDynamicIcon;
    UItemSkinSet();
};
