#pragma once
#include "CoreMinimal.h"
#include "FSDUserWidget.h"
#include "SpaceRigBarMenuItem.generated.h"

class UDrinkableDataAsset;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class USpaceRigBarMenuItem : public UFSDUserWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDrinkableDataAsset* Drink;
    
    bool SpecialEditionSelected;
    USpaceRigBarMenuItem();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Unselect();
    void Select();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UDrinkableDataAsset* GetSelectedDrinkableType();
};
