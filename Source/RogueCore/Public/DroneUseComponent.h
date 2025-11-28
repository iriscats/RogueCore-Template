#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateEventDelegate.h"
#include "DroneFinishedUsingDelegate.h"
#include "DroneUseProgressDelegate.h"
#include "EInputKeys.h"
#include "DroneUseComponent.generated.h"

class APlayerCharacter;
class UDialogDataAsset;
class UPawnStat;
class USingleUsableComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UDroneUseComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDroneFinishedUsing OnUsed;
    
    FDelegateEvent OnBeginUse;
    FDelegateEvent OnStopUse;
    FDroneUseProgress OnProgress;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* BoscoLaserpointerShout;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USingleUsableComponent> SyncToUsable;
    UPawnStat* UseSpeedStat;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float Progress;
    float UseDuration;
    bool ResetOnFail;
    bool CanUse;
    UDroneUseComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SyncedUsableUserCountChangedResponse(int32 userCount);
    void SyncedUsableUsedResponse(APlayerCharacter* User, EInputKeys Key);
    void SyncedUsableBeginUseResponse(APlayerCharacter* User, EInputKeys Key);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetUseDuration(float NewUseDuration);
    void SetCanUse(bool NewCanUse);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetProgress() const;
    void EndUse();
    void BeginUse();
};
