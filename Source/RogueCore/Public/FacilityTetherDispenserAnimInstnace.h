#pragma once
#include "CoreMinimal.h"
#include "EHackingPodState.h"
#include "ItemDispenserAnimInstance.h"
#include "FacilityTetherDispenserAnimInstnace.generated.h"

UCLASS(Blueprintable, NonTransient)
class UFacilityTetherDispenserAnimInstnace : public UItemDispenserAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EHackingPodState PodState;
    
    bool ShouldShowDispenser;
    bool ShouldCloseFromDispenser;
    bool ShouldShowButton;
    bool ShouldHideButton;
    UFacilityTetherDispenserAnimInstnace();
};
