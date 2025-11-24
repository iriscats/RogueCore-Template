#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "ItemRefundListItem.h"
#include "ItemRefundList.generated.h"

class UObject;
UCLASS(Blueprintable)
class UItemRefundList : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ResetListOnSave;
    
    TArray<TSoftObjectPtr<UObject>> Items;
    TMap<FGuid, FItemRefundListItem> ItemsToRefund;
    UItemRefundList();
};
