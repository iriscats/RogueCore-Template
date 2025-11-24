#pragma once
#include "CoreMinimal.h"
#include "SchematicItem.h"
#include "OverclockShematicItem.generated.h"

class UItemID;
class UItemUpgrade;
class UUpgradableGearComponent;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UOverclockShematicItem : public USchematicItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemID* OwningItem;
    
    UItemUpgrade* Overclock;
    UOverclockShematicItem();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UUpgradableGearComponent* GetOwningGearComponent() const;
};
