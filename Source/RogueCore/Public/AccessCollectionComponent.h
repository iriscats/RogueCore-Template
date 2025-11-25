#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AccessCollectionComponent.generated.h"

class UAccessCondition;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UAccessCollectionComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<UAccessCondition*> AccessConditions;
    
    UAccessCollectionComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void RemoveCondition(UAccessCondition* Condition);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasCondition(const UAccessCondition* Condition) const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddCondition(UAccessCondition* Condition);
};
