#pragma once
#include "CoreMinimal.h"
#include "DeepPathfinderCharacter.h"
#include "Maggot.generated.h"

class USimpleHealthComponent;
UCLASS(Blueprintable)
class AMaggot : public ADeepPathfinderCharacter {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimpleHealthComponent* HealthComponent;
    
    AMaggot(const FObjectInitializer& ObjectInitializer);
};
