#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DiscordEoMData.h"
#include "DiscordEoMDataDelegateDelegate.h"
#include "DiscordRewardNotification.h"
#include "DiscordServerInviteData.h"
#include "OnDiscordServerCountLoadedDelegate.h"
#include "OnDiscordServerInfoLoadedDelegate.h"
#include "OnDiscordUserInServerDelegate.h"
#include "ResponseSuccessChangedDelegate.h"
#include "DiscordWrapper.generated.h"

UCLASS(Blueprintable)
class UDiscordWrapper : public UObject {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDiscordServerInviteData ServerInfo;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResponseSuccessChanged OnResponseSuccessChanged;
    bool LastResponseSuccessful;
    FDiscordEoMDataDelegate OnDiscordEoMDataEvent;
    bool UserIn;
    FDiscordRewardNotification rewardNotification;
    int32 UserInStatus;
    bool HasEoM;
    FDiscordEoMData EoMData;
    bool IsConnected;
    bool ServerInfoLoaded;
    FOnDiscordServerInfoLoaded OnDiscordServerInfoLoaded;
    FOnDiscordServerCountLoaded OnDiscordServerCountLoaded;
    FOnDiscordUserInServer OnDiscordUserInServer;
    UDiscordWrapper();
    UFUNCTION(BlueprintCallable)
    void RequestUserInServer();
    void RequestFactionAdjustment(int32 Faction, bool Force);
    void RequestEoMData();
    void RequestDiscordServerInfo();
    void RejectInviteSignature();
    void IgnoreInviteSignature();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetAvatarURL();
    void AdjustFaction();
    void AcceptInviteSignature();
};
