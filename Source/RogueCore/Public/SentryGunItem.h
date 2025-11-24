#pragma once
#include "CoreMinimal.h"
#include "PlaceableItem.h"
#include "SentryGunItem.generated.h"

class UItemUpgrade;
UCLASS(Blueprintable, NoExport)
class ASentryGunItem : public APlaceableItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UItemUpgrade*> upgrades;
    
    ASentryGunItem(const FObjectInitializer& ObjectInitializer);
};
