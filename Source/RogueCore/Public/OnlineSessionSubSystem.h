#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EDisconnectReason.h"
#include "EOnlineSessionType.h"
#include "OnlineSessionSubSystem.generated.h"

class UFSDSessionUpdater;
UCLASS(Blueprintable)
class UOnlineSessionSubSystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    bool IsJoiningInvite;

    bool CanPlayOnline;

    EDisconnectReason DisconnectReason;

    FString DisconnectErrorCode;

    UFSDSessionUpdater* SessionUpdater;

    UOnlineSessionSubSystem();

    UFUNCTION(BlueprintCallable)

    void SetShouldAdvertiseInServerlist(bool bShouldAdvertise);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOnlineSessionType SessionType;
    
    FString SessionPassword;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsJoiningInvite;
    bool CanPlayOnline;
    EDisconnectReason DisconnectReason;
    FString DisconnectErrorCode;
    UFSDSessionUpdater* SessionUpdater;
    UOnlineSessionSubSystem();
    UFUNCTION(BlueprintCallable)
    void SetShouldAdvertiseInServerlist(bool bShouldAdvertise);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetSessionPassword(const FString& Password);
    void SetOverrideMaxPlayerCount(int32 count);
    void SetOnlineSessionType(const EOnlineSessionType NewType);
    void SetIsUsingOnlineFeatures(bool bIsOnlineFeatureUsed);
    void OnNewFSDSessionID(const FString& SessionId);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPendingInvitePasswordProtected();
    bool HasPendingInvite() const;
    EOnlineSessionType GetSessionType() const;
    int32 GetOverrideMaxPlayerCount() const;
    int32 GetMaxPublicConnections() const;
    FString GetDisconnectErrorCode() const;
    bool GetCanPlayOnline() const;
    void CloseSessionLobby();
    void ClearDisconnectError();
    void CancelJoin();
};
