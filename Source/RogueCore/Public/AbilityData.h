#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SavableDataAsset.h"
#include "Templates/SubclassOf.h"
#include "AbilityData.generated.h"

class UAbilityWidget;
class UBXEUnlockCollection;
class UDialogDataAsset;
class UTexture2D;
UCLASS(Blueprintable)
class UAbilityData : public USavableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
    FText Description;
    TSubclassOf<UAbilityWidget> AbilityWidgetOverride;
    UTexture2D* PreviewImage;
    FLinearColor Color;
    UDialogDataAsset* AbilityFailedShout;
    UBXEUnlockCollection* AbilityUpgrades;
    UAbilityData();
};
