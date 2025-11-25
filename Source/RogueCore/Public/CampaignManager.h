#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "ECampaignType.h"
#include "Templates/SubclassOf.h"
#include "CampaignManager.generated.h"

class AFSDPlayerController;
class UCampaign;
class UDifficultySetting;
class UFSDSaveGame;
class UStage;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API UCampaignManager : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCampaignCompletedDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCampaignChangedDelegate);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCampaignCompletedDelegate OnCampaignCompleted;
    FCampaignChangedDelegate OnCampaignChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCampaign> MainCampaign;
    TArray<TSubclassOf<UCampaign>> WeeklyCampaigns;
    TArray<TSubclassOf<UCampaign>> MatrixCoreHuntCampaigns;
    TArray<TSubclassOf<UCampaign>> SideCampaigns;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UCampaign>> EventCampaigns;
    UCampaign* ActiveCampaign;
    int32 NumFailedRequests;
    bool WeeklyBackendDataValid;
    int32 WeeklyBackendSeed;
    FDateTime WeeklyBackendExpirationTime;
    FDateTime LastRequestTime;
    UCampaignManager();
    UFUNCTION(BlueprintCallable)
    void StartNewCampaign(TSubclassOf<UCampaign> campaignClass, UFSDSaveGame* SaveGame);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void SkipMainCampaign(UObject* WorldContextObject);
    void OnEventsRefreshed();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsWeeklyCampaignCompleted(UObject* WorldContext, ECampaignType campaigntype) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInCampaignMission(AFSDPlayerController* Player) const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    bool IsCampaignRestrictionsMet(UObject* WorldContextObject, UStage* Mission, UDifficultySetting* optionalDifficulty) const;
    bool IsCampaignMission(UObject* WorldContextObject, UStage* Mission) const;
    bool IsActiveCampaign(UCampaign* Campaign) const;
    TArray<TSubclassOf<UCampaign>> GetUncompletedCampaigns(AFSDPlayerController* Player) const;
    TArray<TSubclassOf<UCampaign>> GetCompletedSideCampaigns(AFSDPlayerController* Player) const;
    UStage* GetCampaingMissionFromSeeds(UObject* WorldContextObject, int32 globalSeed, int32 missionSeed) const;
    UStage* GetCampaingMission(const TArray<UStage*>& missions, int32 missionSeed) const;
    void CompleteCampaignWithNoMissions(TSubclassOf<UCampaign> campaignClass, UFSDSaveGame* SaveGame);
    void AbortActiveCampaign(UFSDSaveGame* SaveGame);
};
