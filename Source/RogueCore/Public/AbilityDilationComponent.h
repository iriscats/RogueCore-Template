#pragma once
#include "CoreMinimal.h"
#include "AbilityComponent.h"
#include "AbilityDilationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAbilityDilationComponent : public UAbilityComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeDilation;
    
    UAbilityDilationComponent(const FObjectInitializer& ObjectInitializer);
};
