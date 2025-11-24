#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NisseAnimInstance.h"
#include "EasterBunnyAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROGUECORE_API UEasterBunnyAnimInstance : public UNisseAnimInstance {
    GENERATED_BODY()
public:
    UEasterBunnyAnimInstance(const FObjectInitializer& ObjectInitializer);
};