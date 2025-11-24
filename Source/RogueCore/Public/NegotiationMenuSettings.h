#pragma once
#include "CoreMinimal.h"
#include "NegotiationMenuSettings.generated.h"

class UBXENegotiationWidget;
USTRUCT(BlueprintType)
struct FNegotiationMenuSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UBXENegotiationWidget> NegotiationWidget;
    
    int32 Z_Order;
    int32 InitialCountDown;
    int32 AdditionalCountDown;
    ROGUECORE_API FNegotiationMenuSettings();
};
