#pragma once
#include "CoreMinimal.h"
#include "AbilityComponent.h"
#include "AbilityDilationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAbilityDilationComponent : public UAbilityComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeDilation;
    
    UAbilityDilationComponent(const FObjectInitializer& ObjectInitializer);
};
