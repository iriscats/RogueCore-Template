#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GymBarOrder.generated.h"

class UDrinkableDataAsset;
UCLASS(Blueprintable)
class ROGUECORE_API UGymBarOrder : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDrinkableDataAsset* Drink;
    
    int32 SetAmount;
    int32 RepsPerSet;
    UGymBarOrder();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UDrinkableDataAsset* GetDrink() const;
};
