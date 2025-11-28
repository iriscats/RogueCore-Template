#pragma once
#include "CoreMinimal.h"

#include "UINotificationItem.generated.h"

USTRUCT(BlueprintType)
struct FUINotificationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGuid> NotificationIDs;
    
    ROGUECORE_API FUINotificationItem();
};
