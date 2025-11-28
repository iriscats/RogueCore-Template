#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemAggregator.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UItemAggregator : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CounterText;
    
    UItemAggregator(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UnbindAllEvents();
};
