#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "ActiveOutline.h"
#include "DialogVoiceSettings.h"
#include "EAsyncLoadPriority.h"
#include "EShoutType.h"
#include "MissionShoutDelegateDelegate.h"
#include "MissionShoutEndDelegateDelegate.h"
#include "MissionShoutQueueItem.h"
#include "Templates/SubclassOf.h"
#include "CommunicationComponent.generated.h"

class APlayerCharacter;
class UAudioComponent;
class UCharacterShoutsData;
class UDialogDataAsset;
class UObject;
class UShoutWidget;
class USoundBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCommunicationComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FShoutDelegate, APlayerCharacter*, InSender, FText, InText, float, InDuration);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FShoutDelegate OnSubtitleShout;
    FShoutDelegate OnPlayerShout;
    FMissionShoutDelegate OnMissionShout;
    FMissionShoutEndDelegate OnMissionShoutEnd;
    FMissionShoutEndDelegate OnMissionControlFinished;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ShoutingEnabled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UShoutWidget> ShoutWidgetType;
    UCharacterShoutsData* CharacterShouts;
    float MinShoutDelay;
    float CloseRangeShoutDistance;
    FDialogVoiceSettings VoiceSettings;
    TMap<UDialogDataAsset*, float> DelayedShouts;
    FGameplayTagContainer KillShoutAllowedTags;
    bool bMissionControlPaused;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* MissionControlAudioComponent;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UShoutWidget*> ActiveShouts;
    TArray<FActiveOutline> ActiveOutlines;
    APlayerCharacter* Character;
    UDialogDataAsset* LastShout;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAudioComponent> ShoutAudioComponent;
    TMap<UDialogDataAsset*, float> ShoutHistory;
    TArray<FMissionShoutQueueItem> MissionShoutQueue;
    UCommunicationComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopMissionControl(bool InClearQueue);
    void ShoutCustomOrDefault(UDialogDataAsset* CustomShout, EShoutType DefaultShout);
    void ShoutCustomLocalOnly(UDialogDataAsset* NewShout);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void ShoutCustomClosestDwarf(UObject* WorldContext, UDialogDataAsset* NewShout, FVector TargetLocation);
    void ShoutCustom(UDialogDataAsset* NewShout);
    void Shout(EShoutType NewShout);
    void SetVoicePitchMultiplier(float InPitch);
    static void SetMissionControlPaused(UObject* WorldContext, bool IsPaused);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void ServerShout(UDialogDataAsset* NewShout, const FDialogVoiceSettings& InVoiceSettings);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerMissionShoutInArea(UDialogDataAsset* NewShout, const int32 Index, const bool bPriority, const FVector Center, const float Radius);
    void ServerMissionShout_Implementation(UDialogDataAsset* NewShout, int32 Index, bool bPriority);
    void Server_SetVoicePitchMultiplier_Implementation(float InPitch);
    void ResetVoicePitchMultiplier();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAudioComponent* PlayPitchedByClass(UObject* WorldContextObject, TSubclassOf<APlayerCharacter> CharacterClass, USoundBase* Sound, UDialogDataAsset* NewShout, EShoutType ShoutType, UAudioComponent* AudioComponent);
    void PlayPitchedAsync(UDialogDataAsset* NewShout, EShoutType ShoutType, bool IgnoreCoolDown, UAudioComponent* AudioComponent, UObject* WorldContextObject, float shoutVolumeMultiplier, EAsyncLoadPriority Priority);
    UAudioComponent* PlayPitched(USoundBase* Sound, UDialogDataAsset* NewShout, EShoutType ShoutType, bool IgnoreCoolDown, UAudioComponent* AudioComponent, UObject* WorldContextObject);
    static int32 MissionShoutLocally(UObject* WorldContext, UDialogDataAsset* NewShout);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void MissionShoutInArea(UObject* WorldContext, UDialogDataAsset* NewShout, const FVector Center, const float Radius);
    static void MissionShout(UObject* WorldContext, UDialogDataAsset* NewShout, bool bPriority);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMissionControlSpeaking() const;
    float GetVoicePitchMultiplier() const;
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void ClientShout(APlayerCharacter* Sender, UDialogDataAsset* NewShout, int32 Index, const FDialogVoiceSettings& InVoiceSettings);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientMissionShout(UDialogDataAsset* NewShout, int32 Index, bool bPriority);
};
