#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OnlineSubsystemTypes.h"
#include "OnlineSessionClient.h"
#include "EDisconnectReason.h"
#include "EFSDMissionStatus.h"
#include "EFSDNATType.h"
#include "EMissionStructure.h"
#include "EServerDistance.h"
#include "EServerSortOrder.h"
#include "FriendInfo.h"
#include "Templates/SubclassOf.h"
#include "SessionHandling.generated.h"

class APlayerCharacter;
class UBiome;
class UDifficultySetting;
class UFSDGameInstance;
class UObject;
class UPlayerCharacterID;
class UStageTemplate;
UCLASS(Blueprintable)
class USessionHandling : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USessionHandling();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void StopVoice(UObject* WorldContextObject);
    
    static void StartVoice(UObject* WorldContextObject);
    UFUNCTION(BlueprintCallable)
    static bool StartSearchForFriends(int32 LocalUserNum, UFSDGameInstance* GameInstance);
    static bool StartSearchForBlockedUsers(int32 LocalUserNum);
    static void StartCheckForInstalledDLC(UObject* WorldContextObject);
    static void SortServerList(UObject* WorldContextObject, EServerSortOrder Order, bool Reverse, bool sortByFriends, UPARAM(Ref) TArray<FOnlineSessionSearchResult>& servers);
    static void ShowStoreUI(UObject* WorldContextObject);
    static void ShowInviteUI(UObject* WorldContextObject);
    static void JoinOfficialXboxClub(UObject* WorldContextObject);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsVoiceChatting();
    static bool IsInActiveSession();
    static bool IsDisconnectReasonAKick(EDisconnectReason reason);
    static FString GetVoiceStatus();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FText GetSessionJoinError(UObject* WorldContextObject);
    static bool GetOnlinePlayerName(int32 LocalUserNum, FString& Name);
    static EFSDNATType GetNATType(UObject* WorldContextObject);
    static EMissionStructure GetMissionStructure(const FOnlineSessionSearchResult& Result);
    static FString GetLoginStatus(int32 LocalUserNum);
    static FString GetHostUsername(UObject* WorldContextObject);
    static FString GetHostUniqueId(UObject* WorldContextObject);
    static bool GetFriendsList(int32 LocalUserNum, TArray<FFriendInfo>& Players);
    static FString GetFriendlyServerNameSanitized(UObject* WorldContextObject);
    static FString GetFriendlyServerName(UObject* WorldContextObject);
    static bool GetCurrentSessionState(FString& sessionState, FString& ID);
    static bool FSDUpdateSessionInfo(UObject* WorldContextObject);
    static EFSDMissionStatus FSDMissionStatus(const FOnlineSessionSearchResult& Result);
    static void FSDListen(UObject* WorldContextObject);
    static bool FSDIsSessionValid(const FOnlineSessionSearchResult& Result);
    static bool FSDIsPrivateServer(const FOnlineSessionSearchResult& Result);
    static bool FSDIsPasswordRequired(const FOnlineSessionSearchResult& Result);
    static bool FSDIsFullServer(const FOnlineSessionSearchResult& Result);
    static bool FSDIsEliteDeepDive(const FOnlineSessionSearchResult& Result);
    static bool FSDIsClassLocked(const FOnlineSessionSearchResult& Result);
    static bool FSDHasGameStarted(const FOnlineSessionSearchResult& Result);
    static bool FSDGetServerStartTime(const FOnlineSessionSearchResult& Result, FDateTime& StartTime);
    static FString FSDGetServerNameSanitized(const FOnlineSessionSearchResult& Result);
    static FString FSDGetServerName(const FOnlineSessionSearchResult& Result);
    static FString FSDGetServerID(const FOnlineSessionSearchResult& Result);
    static FString FSDGetRegion(const FOnlineSessionSearchResult& Result);
    static TArray<UPlayerCharacterID*> FSDGetPlayerClassIDs(const FOnlineSessionSearchResult& Result);
    static TArray<TSubclassOf<APlayerCharacter>> FSDGetPlayerClasses(const FOnlineSessionSearchResult& Result);
    static int32 FSDGetNumPlayers(const FOnlineSessionSearchResult& Result);
    static int32 FSDGetMissionSeed(const FOnlineSessionSearchResult& Result);
    static FString FSDGetMapName(const FOnlineSessionSearchResult& Result);
    static FString FSDGetHostUserID(const FOnlineSessionSearchResult& Result);
    static int32 FSDGetGlobalMissionSeed(const FOnlineSessionSearchResult& Result);
    static float FSDGetDistanceFloat(const FOnlineSessionSearchResult& Result);
    static EServerDistance FSDGetDistance(const FOnlineSessionSearchResult& Result);
    static UDifficultySetting* FSDGetDifficulty(const FOnlineSessionSearchResult& Result);
    static FString FSDGetBuildId(const FOnlineSessionSearchResult& Result);
    static bool FSDCancelFindSessions(UObject* WorldContextObject);
    static bool FindBestQuickJoinServer(UObject* WorldContextObject, UPARAM(Ref) TArray<FOnlineSessionSearchResult>& sessions, UDifficultySetting* Difficulty, UBiome* Biome, UStageTemplate* MissionTemplate, FOnlineSessionSearchResult& OutResult);
    static bool AllowLinkToExternalFeedback(UObject* WorldContextObject);
};
