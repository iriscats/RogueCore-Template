#pragma once
#include "CoreMinimal.h"
#include "UsableChangedSignatureDelegate.h"
#include "UsableComponent.h"
#include "UsedBySignatureDelegate.h"
#include "InstantUsable.generated.h"

class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UInstantUsable : public UUsableComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUsedBySignature OnUsedBy;
    
    FUsableChangedSignature OnUsableChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowUsingUI;
    USoundCue* AudioCompletedUse;
    bool UseDelayedAudio;
    float AudioDelay;
    bool RefreshDelayOnNewUse;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Usable, meta=(AllowPrivateAccess=true))
    bool usable;
    bool TurnOffAfterUse;
    UInstantUsable(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetCanUse(bool CanUse);
    UFUNCTION()
    void OnRep_Usable();
};
