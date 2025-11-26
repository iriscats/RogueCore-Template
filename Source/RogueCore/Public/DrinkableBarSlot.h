#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DrinkableBarSlot.generated.h"

class ADrinkableActor;
USTRUCT(BlueprintType)
struct FDrinkableBarSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector WorldLocation = FVector::ZeroVector;
    
    TWeakObjectPtr<ADrinkableActor> DrinkableActor;

};
