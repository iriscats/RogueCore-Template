#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EBlueprintablePrivilegeResults.h"
#include "EBlueprintableUserPrivileges.h"
#include "EInviteBlockReason.h"
#include "OnGetIsUpdatePendingBPDelegate.h"
#include "OnGetUserPrivilegeCompleteBPDelegateDelegate.h"
#include "OnProfileUIClosedBPDelegate.h"
#include "OnShowWebUrlClosedBPDelegate.h"
#include "FSDOnlineSystemUtils.generated.h"

class APlayerState;
class UFSDGameInstance;
class UObject;
UCLASS(Blueprintable)
class UFSDOnlineSystemUtils : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFSDOnlineSystemUtils();
    UFUNCTION(BlueprintCallable)
    static void TryToResolvePrivilege(const APlayerState* PlayerState, EBlueprintableUserPrivileges Privilege, EBlueprintablePrivilegeResults reason);
    
    static void ShowUpgradeAccountUI();
    static void ShowAccountPicker(UFSDGameInstance* gInstance, const int32 GamePlayerID);
    static void OpenURLInOverlay(const FString& URL, FOnShowWebUrlClosedBP OnOverlayClosed);
    static void OpenProfileWithEvent(APlayerState* Requestor, APlayerState* Requestee, FOnProfileUIClosedBP OnProfileWindowClosed);
    static void OpenProfileByUserId(APlayerState* Requestor, const FString& RequesteeUserID);
    static void OpenProfile(APlayerState* Requestor, APlayerState* Requestee);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText OnlinePlayBlockReasonToString(EBlueprintablePrivilegeResults reason);
    static void GetOnlinePlayBlockReasons(TArray<EBlueprintablePrivilegeResults>& reasons);
    static void GetIsUpdatePending(const FOnGetIsUpdatePendingBP& Delegate);
    static void GetIsPrivilegeAllowed(const APlayerState* PlayerState, EBlueprintableUserPrivileges Privilege, const FOnGetUserPrivilegeCompleteBPDelegate& Delegate);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FText GetInviteFeatureBlockReason(UObject* WorldContextObject, EInviteBlockReason reason);
    static EInviteBlockReason CanPlayerInvite(UObject* WorldContextObject);
};
