#pragma once
#include "CoreMinimal.h"

#include "UINotificationItem.h"
#include "ItemUINotifications.generated.h"

class UFSDSaveGame;
USTRUCT(BlueprintType)
struct FItemUINotifications {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FUINotificationItem> UINotifications;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<FGuid> UINotificationSet;
    UFSDSaveGame* SaveGame;
    ROGUECORE_API FItemUINotifications();
 
};
