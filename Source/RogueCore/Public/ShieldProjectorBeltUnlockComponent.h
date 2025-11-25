#pragma once
#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "PerkInputUnlockComponent.h"
#include "Templates/SubclassOf.h"
#include "ShieldProjectorBeltUnlockComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UShieldProjectorBeltUnlockComponent : public UPerkInputUnlockComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> Shield;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle TimeoutHandle;
    float Duration;
    UShieldProjectorBeltUnlockComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopShieldProjector();
    void StartShieldProjector();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void On_StartShieldProjector();
    void On_EndShieldProjector();
};
