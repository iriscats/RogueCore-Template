#pragma once
#include "CoreMinimal.h"
#include "PlaceableItem.h"
#include "SentryGunItem.generated.h"

class UItemUpgrade;
UCLASS(Blueprintable)
class ASentryGunItem : public APlaceableItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UItemUpgrade*> upgrades;
    
    ASentryGunItem(const FObjectInitializer& ObjectInitializer);
};
