#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Example01State.h"
#include "TargetChangedDelegateDelegate.h"
#include "Example01ActorComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UExample01ActorComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTargetChangedDelegate OnTargetChanged;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetTrackingTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    FExample01State State;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 TargetCounter;
    UExample01ActorComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetTarget(AActor* NewTarget);
    UFUNCTION(BlueprintCallable)
    void OnRep_State(const FExample01State& oldState);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTargetCount() const;
    float GetCurrentTargetTime() const;
    AActor* GetCurrentTarget() const;
};
