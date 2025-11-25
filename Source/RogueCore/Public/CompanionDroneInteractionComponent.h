#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "FloatDelegateDelegate.h"
#include "CompanionDroneInteractionComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCompanionDroneInteractionComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnStartedUsing;
    
    FDelegate OnStoppedUsing;
    FDelegate OnUsed;
    FFloatDelegate OnUseProgressUpdated;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InteractionTime;
    bool CanUse;
    bool DisableOnuse;
    UCompanionDroneInteractionComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopUsing();
    void StartUsing(float interactionSpeed);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInUse() const;
    bool GetCanUse() const;
};
