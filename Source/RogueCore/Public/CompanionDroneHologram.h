#pragma once
#include "CoreMinimal.h"
#include "CompanionDroneHologram.generated.h"

class USingleUsableComponent;
class UUserWidget;
USTRUCT(BlueprintType)
struct FCompanionDroneHologram {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USingleUsableComponent> usable;
    
    TWeakObjectPtr<UUserWidget> Widget;
    ROGUECORE_API FCompanionDroneHologram();
};
