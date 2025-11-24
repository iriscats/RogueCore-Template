#pragma once
#include "CoreMinimal.h"
#include "CarriableItem.h"
#include "DorrettaHead.generated.h"

class UCarriableComponent;
class UCarriableInstantUsable;
UCLASS(Blueprintable, NoExport)
class ADorrettaHead : public ACarriableItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCarriableInstantUsable* usable;
    
    UCarriableComponent* CarriableComponent;
    ADorrettaHead(const FObjectInitializer& ObjectInitializer);
};
