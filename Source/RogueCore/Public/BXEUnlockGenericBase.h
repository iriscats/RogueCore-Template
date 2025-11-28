#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockBase.h"
#include "BXEUnlockGenericBase.generated.h"

class UTexture2D;
UCLASS(Blueprintable)
class ROGUECORE_API UBXEUnlockGenericBase : public UBXEUnlockBase {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DisplayText;
    
    FText Description;
    TSoftObjectPtr<UTexture2D> Icon;
    UBXEUnlockGenericBase();
};
