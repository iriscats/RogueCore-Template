#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ChallengeInfo.h"
#include "ClaimStatusChangedDelegate.h"
#include "EPickaxePartLocation.h"
#include "OnScripChallengeUpdatedDelegate.h"
#include "OnTokensChangedSignatureDelegate.h"
#include "OnVanityTreeResetDelegate.h"
#include "OnXPChangedSignatureDelegate.h"
#include "SeasonLevel.h"
#include "SeasonMissionResult.h"
#include "SeasonsSubsystem.generated.h"

class AFSDPlayerController;
class AFSDPlayerState;
class UDataAsset;
class UItemSkin;
class UMissionStat;
class UObject;
class UPickaxePart;
class UPlayerCharacterID;
class USeasonChallenge;
class USeasonEventData;
class USpecialEvent;
class UTextureRenderTarget2D;
class UVanityItem;
UCLASS(Blueprintable)
class USeasonsSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnXPChangedSignature OnXpChanged;
    
    FOnTokensChangedSignature OnTokensChanged;
    FOnVanityTreeReset OnVanityTreeReset;
    FOnScripChallengeUpdated OnScripChallengeUpdated;
    FClaimStatusChanged OnClaimStatusChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USpecialEvent> forcedSeasonEvent;
    FTimespan NewChallengeTimeSpan;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSeasonMissionResult TempSeasonMissionResult;
    FSeasonMissionResult LatestMissionSeasonResult;
    USeasonsSubsystem();
    UFUNCTION(BlueprintCallable)
    FTimespan TimeToNewChallenge();
    void RerollChallenge(int32 Index);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void OnStatChanged(UObject* WorldContext, UMissionStat* Stat, float Value, float change);
    void OnScripChallengeCompleted(UObject* WorldContext, UMissionStat* Stat, float Value, float change);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void IsRewardClaimed(int32 Level, bool& IsNormalClaimed, bool& IsSpecialClaimed);
    void InitializeStatsAndChallenges();
    bool HasUnclaimedRewards(int32& Level);
    bool HasClaimedLevelRewards(int32 startLevel, int32 numberOfLevels);
    bool HasClaimedAllRewards();
    int32 GetUnusedHearts();
    int32 GetSeasonXPFromMissionXP(AFSDPlayerState* PlayerState);
    int32 GetSeasonXP();
    int32 GetSeasonNumber() const;
    FText GetSeasonName() const;
    FSeasonMissionResult GetSeasonMissionResult();
    void GetSeasonLevelFromXP(int32 XP, int32& Level, float& currentLevelPercent, int32& currentLevelXP, int32& LevelXPTotal);
    void GetSeasonLevel(int32& Level, float& currentLevelPercent, int32& currentLevelXP, int32& LevelXPTotal);
    bool GetSeasonExpiryDate(FDateTime& ExpiryDate);
    void GetSeasonBought(bool& isBought);
    void GetScriptChallengeInfo(int32& Completed, int32& claimed, int32& Total);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    int32 GetNumberOfTokens(UObject* WorldContextObject);
    int32 GetNumberOfSeasonLevels();
    int32 GetNumberOfClaimedPlagueHeartScrips();
    FSeasonLevel GetNextReward();
    int32 GetLevelXP(int32 Level);
    FSeasonLevel GetLevelReward(int32 Level);
    void GetLevelProgress(int32 Level, float& levelPercent);
    TArray<UDataAsset*> GetAssetReferences(int32 challengeIndex, USeasonChallenge*& outChallenge);
    TArray<FChallengeInfo> GetActiveChallenges(bool canGenerateNewChallenge);
    UTextureRenderTarget2D* GenerateVanityRewardIcon(UVanityItem* Item, UPlayerCharacterID* Character, FTransform Offset, bool rebuildMesh, FVector2D Size);
    UTextureRenderTarget2D* GenerateSkinRewardIcon(UItemSkin* Skin, UPlayerCharacterID* Character, bool bShowCloseUp, FTransform Offset, bool rebuildMesh, FVector2D Size);
    UTextureRenderTarget2D* GeneratePickaxeRewardIcon(UPickaxePart* part, EPickaxePartLocation PickaxePartLocation, UPlayerCharacterID* Character, FTransform Offset, bool rebuildMesh, FVector2D Size);
    bool ConvertHeartsToScrip(int32& scripGained);
    void CompleteSeasonEvent_Server(USeasonEventData* InEvent);
    bool ClaimScripChallenge();
    bool ClaimReward(UObject* WorldContext, AFSDPlayerController* Player, int32 Level, bool isNormalReward);
    void CHEAT_SetSeasonMissionResult(int32 XPFromMission, int32 numberOfChallenges, USeasonEventData* Event);
    void CHEAT_ResetTimeToNewChallenge();
    void CHEAT_ResetReroll();
    void CHEAT_AddChallenge();
    bool CanRerollChallenge();
};
