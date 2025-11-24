#pragma once
#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "BoolDelegateDelegate.h"
#include "DelegateDelegate.h"
#include "PlayerCountChangedSigDelegate.h"
#include "PlayersNegotiationSphere.generated.h"

class APlayerCharacter;
class UNiagaraSystem;
UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UPlayersNegotiationSphere : public USphereComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerCountChangedSig OnInsidePlayerCountChanged;
    
    FDelegate OnNegotiationStart;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoolDelegate OnTrackingChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* TrackingEffect;
    float ChargeupTime;
protected:
    TArray<APlayerCharacter*> playersInside;
    bool IsTracking;
    UPlayersNegotiationSphere(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetTrackPlayers(bool shouldTrack);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetTrackingEffectActive(bool IsActive);
    void SetHeaderText(const FText& inHeaderText);
    APlayerCharacter* GetLastPlayerInside_ServerOnly();
};
