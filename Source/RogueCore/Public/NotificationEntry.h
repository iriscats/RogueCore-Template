#pragma once
#include "CoreMinimal.h"
#include "NotificationEntry.generated.h"

class UObject;
class UWindowWidget;
USTRUCT(BlueprintType)
struct FNotificationEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ObjectInstance;
    
    TSoftClassPtr<UWindowWidget> WindowClass;
    ROGUECORE_API FNotificationEntry();
};
