#pragma once
#include "CoreMinimal.h"
#include "BioBoosterInterfaceAudio.h"
#include "UsableComponentBase.h"
#include "BioBoosterTerminalUsable.generated.h"

class APlayerCharacter;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBioBoosterTerminalUsable : public UUsableComponentBase {
    GENERATED_BODY()
    


public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUsedDelegate, APlayerCharacter*, InUser);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProgressDelegate, float, InProgress);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCanUseDelegate, bool, InCanUse);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCanUseDelegate OnCanUseChanged;
    FUsedDelegate OnUsedBy;
    FProgressDelegate OnProgress;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBioBoosterInterfaceAudio Audio;
    float UseDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_InterfaceActivated, meta=(AllowPrivateAccess=true))
    bool bInterfaceActivated;
    UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_CollectedRewards, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<APlayerCharacter>> CollectedRewards;
    UBioBoosterTerminalUsable(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_InterfaceActivated();
    UFUNCTION()
    void OnRep_CollectedRewards(const TArray<TWeakObjectPtr<APlayerCharacter>>& OldCollectedRewards);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CanUseInterface() const;
};
