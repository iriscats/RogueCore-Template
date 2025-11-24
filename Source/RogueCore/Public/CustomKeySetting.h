#pragma once
#include "CoreMinimal.h"
#include "EKeyBindingAxis.h"
#include "CustomKeySetting.generated.h"

USTRUCT(BlueprintType)
struct FCustomKeySetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SaveID;
    
    FText Description;
    TArray<FName> ActionNames;
    EKeyBindingAxis ActionAxis;
    ROGUECORE_API FCustomKeySetting();
};
