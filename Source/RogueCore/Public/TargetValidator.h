#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TargetValidator.generated.h"

class AActor;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UTargetValidator : public UObject {
    GENERATED_BODY()
public:
    UTargetValidator();
 
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool ReceiveIsTargetValid(AActor* Owner, AActor* Target) const;
    
};
