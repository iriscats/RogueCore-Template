#pragma once
#include "CoreMinimal.h"
#include "BasicThrowableItem.h"
#include "BasicDepositableItem.generated.h"

class UResourceData;
UCLASS(Blueprintable)
class ABasicDepositableItem : public ABasicThrowableItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* DepositableResource;
    
    ABasicDepositableItem(const FObjectInitializer& ObjectInitializer);
};
