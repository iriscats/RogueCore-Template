#pragma once
#include "CoreMinimal.h"
#include "PawnAfflictionComponent.h"
#include "PlayerAfflictionComponent.generated.h"

class APlayerCharacter;
class UPlayerAfflictionOverlay;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerAfflictionComponent : public UPawnAfflictionComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOverlayDelegate, UPlayerAfflictionOverlay*, Overlay);
    
 
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOverlayDelegate OnShowOverlay;
    FOverlayDelegate OnHideOverlay;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UPlayerAfflictionOverlay*, int32> ActiveOverlays;
    TWeakObjectPtr<APlayerCharacter> Character;
    UPlayerAfflictionComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ShowPlayerOverlay(UPlayerAfflictionOverlay* Overlay);
    void HidePlayerOverlay(UPlayerAfflictionOverlay* Overlay);
};
