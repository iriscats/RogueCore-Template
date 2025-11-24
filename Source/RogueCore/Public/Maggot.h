#pragma once
#include "CoreMinimal.h"
#include "DeepPathfinderCharacter.h"
#include "Maggot.generated.h"

class USimpleHealthComponent;
UCLASS(Blueprintable, NoExport)
class AMaggot : public ADeepPathfinderCharacter {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimpleHealthComponent* HealthComponent;
    
    AMaggot(const FObjectInitializer& ObjectInitializer);
};
