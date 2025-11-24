#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OnlineSubsystemTypes.h"
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
    static void SortServerList(UObject* WorldContextObject, EServerSortOrder Order, bool Reverse, bool sortByFriends, UPARAM(Ref) TArray<FBlueprintSessionResult>& servers);
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
    static EMissionStructure GetMissionStructure(const FBlueprintSessionResult& Result);
    static FString GetLoginStatus(int32 LocalUserNum);
    static FString GetHostUsername(UObject* WorldContextObject);
    static FString GetHostUniqueId(UObject* WorldContextObject);
    static bool GetFriendsList(int32 LocalUserNum, TArray<FFriendInfo>& Players);
    static FString GetFriendlyServerNameSanitized(UObject* WorldContextObject);
    static FString GetFriendlyServerName(UObject* WorldContextObject);
    static bool GetCurrentSessionState(FString& sessionState, FString& ID);
    static bool FSDUpdateSessionInfo(UObject* WorldContextObject);
    static EFSDMissionStatus FSDMissionStatus(const FBlueprintSessionResult& Result);
    static void FSDListen(UObject* WorldContextObject);
    static bool FSDIsSessionValid(const FBlueprintSessionResult& Result);
    static bool FSDIsPrivateServer(const FBlueprintSessionResult& Result);
    static bool FSDIsPasswordRequired(const FBlueprintSessionResult& Result);
    static bool FSDIsFullServer(const FBlueprintSessionResult& Result);
    static bool FSDIsEliteDeepDive(const FBlueprintSessionResult& Result);
    static bool FSDIsClassLocked(const FBlueprintSessionResult& Result);
    static bool FSDHasGameStarted(const FBlueprintSessionResult& Result);
    static bool FSDGetServerStartTime(const FBlueprintSessionResult& Result, FDateTime& StartTime);
    static FString FSDGetServerNameSanitized(const FBlueprintSessionResult& Result);
    static FString FSDGetServerName(const FBlueprintSessionResult& Result);
    static FString FSDGetServerID(const FBlueprintSessionResult& Result);
    static FString FSDGetRegion(const FBlueprintSessionResult& Result);
    static TArray<UPlayerCharacterID*> FSDGetPlayerClassIDs(const FBlueprintSessionResult& Result);
    static TArray<TSubclassOf<APlayerCharacter>> FSDGetPlayerClasses(const FBlueprintSessionResult& Result);
    static int32 FSDGetNumPlayers(const FBlueprintSessionResult& Result);
    static int32 FSDGetMissionSeed(const FBlueprintSessionResult& Result);
    static FString FSDGetMapName(const FBlueprintSessionResult& Result);
    static FString FSDGetHostUserID(const FBlueprintSessionResult& Result);
    static int32 FSDGetGlobalMissionSeed(const FBlueprintSessionResult& Result);
    static float FSDGetDistanceFloat(const FBlueprintSessionResult& Result);
    static EServerDistance FSDGetDistance(const FBlueprintSessionResult& Result);
    static UDifficultySetting* FSDGetDifficulty(const FBlueprintSessionResult& Result);
    static FString FSDGetBuildId(const FBlueprintSessionResult& Result);
    static bool FSDCancelFindSessions(UObject* WorldContextObject);
    static bool FindBestQuickJoinServer(UObject* WorldContextObject, UPARAM(Ref) TArray<FBlueprintSessionResult>& sessions, UDifficultySetting* Difficulty, UBiome* Biome, UStageTemplate* MissionTemplate, FBlueprintSessionResult& OutResult);
    static bool AllowLinkToExternalFeedback(UObject* WorldContextObject);
};
