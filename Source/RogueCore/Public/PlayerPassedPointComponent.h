#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PlayerInfrontState.h"
#include "PlayerMovedPassedDelegateDelegate.h"
#include "PlayerPassedPointComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UPlayerPassedPointComponent : public USceneComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerMovedPassedDelegate OnPlayerMovedPast;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableOnFirstPlayerInFront;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPlayerInfrontState> OldStates;
    UPlayerPassedPointComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnMatchStarted();
};
