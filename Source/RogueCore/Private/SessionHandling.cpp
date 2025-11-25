#include "SessionHandling.h"
#include "Templates/SubclassOf.h"

USessionHandling::USessionHandling() {
}

void USessionHandling::StopVoice(UObject* WorldContextObject) {
}

void USessionHandling::StartVoice(UObject* WorldContextObject) {
}

bool USessionHandling::StartSearchForFriends(int32 LocalUserNum, UFSDGameInstance* GameInstance) {
    return false;
}

bool USessionHandling::StartSearchForBlockedUsers(int32 LocalUserNum) {
    return false;
}

void USessionHandling::StartCheckForInstalledDLC(UObject* WorldContextObject) {
}

void USessionHandling::SortServerList(UObject* WorldContextObject, EServerSortOrder Order, bool Reverse, bool sortByFriends, TArray<FOnlineSessionSearchResult>& servers) {
}

void USessionHandling::ShowStoreUI(UObject* WorldContextObject) {
}

void USessionHandling::ShowInviteUI(UObject* WorldContextObject) {
}

void USessionHandling::JoinOfficialXboxClub(UObject* WorldContextObject) {
}

bool USessionHandling::IsVoiceChatting() {
    return false;
}

bool USessionHandling::IsInActiveSession() {
    return false;
}

bool USessionHandling::IsDisconnectReasonAKick(EDisconnectReason reason) {
    return false;
}

FString USessionHandling::GetVoiceStatus() {
    return TEXT("");
}

FText USessionHandling::GetSessionJoinError(UObject* WorldContextObject) {
    return FText::GetEmpty();
}

bool USessionHandling::GetOnlinePlayerName(int32 LocalUserNum, FString& Name) {
    return false;
}

EFSDNATType USessionHandling::GetNATType(UObject* WorldContextObject) {
    return EFSDNATType::Open;
}

EMissionStructure USessionHandling::GetMissionStructure(const FOnlineSessionSearchResult& Result) {
    return EMissionStructure::SingleMission;
}

FString USessionHandling::GetLoginStatus(int32 LocalUserNum) {
    return TEXT("");
}

FString USessionHandling::GetHostUsername(UObject* WorldContextObject) {
    return TEXT("");
}

FString USessionHandling::GetHostUniqueId(UObject* WorldContextObject) {
    return TEXT("");
}

bool USessionHandling::GetFriendsList(int32 LocalUserNum, TArray<FFriendInfo>& Players) {
    return false;
}

FString USessionHandling::GetFriendlyServerNameSanitized(UObject* WorldContextObject) {
    return TEXT("");
}

FString USessionHandling::GetFriendlyServerName(UObject* WorldContextObject) {
    return TEXT("");
}

bool USessionHandling::GetCurrentSessionState(FString& sessionState, FString& ID) {
    return false;
}

bool USessionHandling::FSDUpdateSessionInfo(UObject* WorldContextObject) {
    return false;
}

EFSDMissionStatus USessionHandling::FSDMissionStatus(const FOnlineSessionSearchResult& Result) {
    return EFSDMissionStatus::SpaceRig;
}

void USessionHandling::FSDListen(UObject* WorldContextObject) {
}

bool USessionHandling::FSDIsSessionValid(const FOnlineSessionSearchResult& Result) {
    return false;
}

bool USessionHandling::FSDIsPrivateServer(const FOnlineSessionSearchResult& Result) {
    return false;
}

bool USessionHandling::FSDIsPasswordRequired(const FOnlineSessionSearchResult& Result) {
    return false;
}

bool USessionHandling::FSDIsFullServer(const FOnlineSessionSearchResult& Result) {
    return false;
}

bool USessionHandling::FSDIsEliteDeepDive(const FOnlineSessionSearchResult& Result) {
    return false;
}

bool USessionHandling::FSDIsClassLocked(const FOnlineSessionSearchResult& Result) {
    return false;
}

bool USessionHandling::FSDHasGameStarted(const FOnlineSessionSearchResult& Result) {
    return false;
}

bool USessionHandling::FSDGetServerStartTime(const FOnlineSessionSearchResult& Result, FDateTime& StartTime) {
    return false;
}

FString USessionHandling::FSDGetServerNameSanitized(const FOnlineSessionSearchResult& Result) {
    return TEXT("");
}

FString USessionHandling::FSDGetServerName(const FOnlineSessionSearchResult& Result) {
    return TEXT("");
}

FString USessionHandling::FSDGetServerID(const FOnlineSessionSearchResult& Result) {
    return TEXT("");
}

FString USessionHandling::FSDGetRegion(const FOnlineSessionSearchResult& Result) {
    return TEXT("");
}

TArray<UPlayerCharacterID*> USessionHandling::FSDGetPlayerClassIDs(const FOnlineSessionSearchResult& Result) {
    return TArray<UPlayerCharacterID*>();
}

TArray<TSubclassOf<APlayerCharacter>> USessionHandling::FSDGetPlayerClasses(const FOnlineSessionSearchResult& Result) {
    return TArray<TSubclassOf<APlayerCharacter>>();
}

int32 USessionHandling::FSDGetNumPlayers(const FOnlineSessionSearchResult& Result) {
    return 0;
}

int32 USessionHandling::FSDGetMissionSeed(const FOnlineSessionSearchResult& Result) {
    return 0;
}

FString USessionHandling::FSDGetMapName(const FOnlineSessionSearchResult& Result) {
    return TEXT("");
}

FString USessionHandling::FSDGetHostUserID(const FOnlineSessionSearchResult& Result) {
    return TEXT("");
}

int32 USessionHandling::FSDGetGlobalMissionSeed(const FOnlineSessionSearchResult& Result) {
    return 0;
}

float USessionHandling::FSDGetDistanceFloat(const FOnlineSessionSearchResult& Result) {
    return 0.0f;
}

EServerDistance USessionHandling::FSDGetDistance(const FOnlineSessionSearchResult& Result) {
    return EServerDistance::Close;
}

UDifficultySetting* USessionHandling::FSDGetDifficulty(const FOnlineSessionSearchResult& Result) {
    return NULL;
}

FString USessionHandling::FSDGetBuildId(const FOnlineSessionSearchResult& Result) {
    return TEXT("");
}

bool USessionHandling::FSDCancelFindSessions(UObject* WorldContextObject) {
    return false;
}

bool USessionHandling::FindBestQuickJoinServer(UObject* WorldContextObject, TArray<FOnlineSessionSearchResult>& sessions, UDifficultySetting* Difficulty, UBiome* Biome, UStageTemplate* MissionTemplate, FOnlineSessionSearchResult& OutResult) {
    return false;
}

bool USessionHandling::AllowLinkToExternalFeedback(UObject* WorldContextObject) {
    return false;
}


