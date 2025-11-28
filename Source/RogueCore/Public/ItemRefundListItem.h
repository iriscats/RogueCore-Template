#pragma once
#include "CoreMinimal.h"

#include "ItemRefundResourceItem.h"
#include "ItemRefundListItem.generated.h"

USTRUCT(BlueprintType)
struct FItemRefundListItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    TMap<FGuid, FItemRefundResourceItem> Resources;
    float CreditCost;
    ROGUECORE_API FItemRefundListItem();
};
