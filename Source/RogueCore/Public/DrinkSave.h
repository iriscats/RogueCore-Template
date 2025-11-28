#pragma once
#include "CoreMinimal.h"

#include "DrinkSave.generated.h"

USTRUCT(BlueprintType)
struct FDrinkSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FGuid> UnlockedDrinks;
    
    bool HasUnlockedSpecial;
    ROGUECORE_API FDrinkSave();
};
