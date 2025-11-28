#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "SentryGunTypeUpgrade.generated.h"

class AItemMarker;
class ARecallableSentryGun;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class USentryGunTypeUpgrade : public UItemUpgrade {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARecallableSentryGun> SentryGunType;
    
    TSubclassOf<AItemMarker> MarkerType;
    USentryGunTypeUpgrade();
};
