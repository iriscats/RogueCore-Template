#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "SkinUnlock.generated.h"

class UItemID;
class UItemSkin;
class UPlayerCharacterID;
UCLASS(Blueprintable, DefaultToInstanced, EditInlineNew)
class USkinUnlock : public UUnlockReward {
    GENERATED_BODY()
    
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemID* OptionalItemID;
    
    UPlayerCharacterID* OptionalCharacterID;
    UItemSkin* Skin;
    USkinUnlock();
};
