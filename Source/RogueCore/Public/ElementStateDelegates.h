#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ElementStateDelegateDelegate.h"
#include "ElementStateDelegates.generated.h"

UCLASS(Blueprintable)
class UElementStateDelegates : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FElementStateDelegate OnChanged;
    
    UElementStateDelegates();
};
