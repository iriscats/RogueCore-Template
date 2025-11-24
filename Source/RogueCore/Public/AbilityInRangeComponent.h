#pragma once
#include "CoreMinimal.h"
#include "AbilityComponent.h"
#include "AbilityInRangeComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAbilityInRangeComponent : public UAbilityComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateTime;
    
    float CacheUpdateTime;
    UAbilityInRangeComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldCountActor(AActor* Actor) const;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActorExit(AActor* Actor);
    void OnActorEnter(AActor* Actor);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnyActorInRange() const;
    UFUNCTION(BlueprintNativeEvent)
    TArray<AActor*> GetRelevantActors() const;
    UFUNCTION(BlueprintNativeEvent)
    float GetMaxRadius() const;
    TArray<AActor*> GetActorsInRange() const;
};
