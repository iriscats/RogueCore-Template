#pragma once
#include "CoreMinimal.h"

#include "EnhancedTrace.generated.h"

class APlayerCharacter;
class UHitscanBaseComponent;
USTRUCT(BlueprintType)
struct FEnhancedTrace {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UHitscanBaseComponent> Component;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> Instigator;
    FVector Origin;
    FVector Direction;
    FVector HitPoint;
    ROGUECORE_API FEnhancedTrace();
};
