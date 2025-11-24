#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FSDEventActivateChangedDelegate.h"
#include "FSDEventCollection.generated.h"

class UFSDEvent;
UCLASS(Blueprintable)
class ROGUECORE_API UFSDEventCollection : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UFSDEvent*> Events;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFSDEventActivateChanged OnEventActiveChanged;
    UFSDEventCollection();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFSDEvent* FindEventHandler(const FName& EventName) const;
    TArray<UFSDEvent*> FindAllEventHandlers(const FName& EventName) const;
};
