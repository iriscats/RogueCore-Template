#pragma once
#include "CoreMinimal.h"
#include "EInputKeys.h"
#include "GenericUsableDelegateDelegate.h"
#include "GenericUsableWithUsableReferenceDelegateDelegate.h"
#include "OnFailedDelegate.h"
#include "ProgressSignatureDelegate.h"
#include "UsableChangedSignatureDelegate.h"
#include "UsableComponent.h"
#include "UsedBySignatureDelegate.h"
#include "UsedBySignatureWithUsableReferenceDelegate.h"
#include "UserCountChangedDelegateDelegate.h"
#include "SingleUsableComponent.generated.h"

class APlayerCharacter;
class UAudioComponent;
class UDialogDataAsset;
class UPawnStat;
class USoundCue;
class UTexture2D;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USingleUsableComponent : public UUsableComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUsedBySignature OnUsedBy;
    
    FUsedBySignatureWithUsableReference OnUsedByWithRef;
    FUsedBySignatureWithUsableReference OnUseBeginWithRef;
    FGenericUsableWithUsableReferenceDelegate OnUseEndWithRef;
    FUsedBySignature OnUseBegin;
    FGenericUsableDelegate OnUseEnd;
    FProgressSignature OnProgress;
    FUsableChangedSignature OnUsableChanged;
    FUserCountChangedDelegate OnUserCountChanged;
    FOnFailed OnFailed;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* AudioBeginUse;
    USoundCue* AudioFailedUse;
    USoundCue* AudioCompletedUse;
    USoundCue* AudioProgress;
    FName AudioProgressParam;
    UDialogDataAsset* BoscoLaserpointerShout;
    bool CoopUse;
    UPawnStat* UseSpeedStat;
    float CoopUseMultiplier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Usable, meta=(AllowPrivateAccess=true))
    bool usable;
    bool TurnOffAfterUse;
    bool MultipleUse;
    bool bShowUsingUI;
    TSoftObjectPtr<UTexture2D> UsableIcon;
    float UseDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Progress;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DesiredProgress, meta=(AllowPrivateAccess=true))
    float DesiredProgress;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_UserCount, meta=(AllowPrivateAccess=true))
    int32 userCount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* AudioBeginUseInstance;
    UAudioComponent* AudioProgressInstance;
    bool bAudioProgressPlaying;
    USingleUsableComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void Use(APlayerCharacter* User, EInputKeys Key, float DeltaTime);
    void SetProgress(float Value);
    void SetCanUse(bool CanUse);
    UFUNCTION()
    void OnRep_UserCount();
    UFUNCTION()
    void OnRep_Usable();
    UFUNCTION()
    void OnRep_DesiredProgress();
    void Cheat_Use(APlayerCharacter* User, EInputKeys Key);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayFailedAudio();
};
