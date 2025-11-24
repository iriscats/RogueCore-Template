#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AccessRequirementComponent.generated.h"

class UAccessCondition;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UAccessRequirementComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAccessCondition* AccessCondition;
    
    UAccessRequirementComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAccessCondition* GetAccessCondition() const;
};
