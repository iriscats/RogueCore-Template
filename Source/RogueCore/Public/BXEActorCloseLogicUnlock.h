#pragma once
#include "CoreMinimal.h"
#include "BXELogicUnlockComponent.h"
#include "BXEActorCloseLogicUnlock.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBXEActorCloseLogicUnlock : public UBXELogicUnlockComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsInRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredActorCount;
    float UpdateTime;
    float CacheUpdateTime;
    bool ShouldDebugPrint;
    UBXEActorCloseLogicUnlock(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldCountActor(AActor* Actor) const;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActorExit(AActor* Actor);
    void OnActorEnter(AActor* Actor);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnyActorInRange() const;
    float GetTotalModifierValueAdditive() const;
    TArray<AActor*> GetRelevantActors() const;
    int32 GetNumActorsInRange() const;
    float GetMaxRadius() const;
    float GetClampedInRangeModifierValue() const;
    TArray<AActor*> GetActorsInRange() const;
};
