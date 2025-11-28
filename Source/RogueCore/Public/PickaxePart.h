#pragma once
#include "CoreMinimal.h"
#include "EPickaxePartLocation.h"
#include "SavablePrimaryDataAsset.h"
#include "PickaxePart.generated.h"

class UItemAquisitionBase;
class UPickaxePartItem;
UCLASS(Blueprintable)
class ROGUECORE_API UPickaxePart : public USavablePrimaryDataAsset {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemAquisitionBase* Aquisition;
    UPickaxePartItem* Item;
    UPickaxePart();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetUnlockedFromStart() const;
    EPickaxePartLocation GetPrefferedLocation() const;
};
