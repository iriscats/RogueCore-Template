#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "ECampaignMutators.h"
#include "ECampaignType.h"
#include "Templates/SubclassOf.h"
#include "Campaign.generated.h"

class AFSDPlayerController;
class APlayerController;
class UCampaign;
class UCampaignMission;
class UCampaignRequirement;
class UDialogDataAsset;
class UDifficultySetting;
class UGameActivityAssignmentType;
class UMissionStat;
class UPlayerCharacterID;
class UReward;
class UTexture2D;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API UCampaign : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasMissions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCampaignMission*> missions;
    TArray<UReward*> RewardsOnCampaignStart;
    TArray<UReward*> RewardsOnCompletion;
    UDialogDataAsset* CampaignCompleteShout;
    TArray<UCampaignRequirement*> Requirements;
    TArray<UCampaignRequirement*> VisibilityRequirements;
    UPlayerCharacterID* RequiredCharacterID;
    TArray<UDifficultySetting*> RestrictedToDifficulties;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Progress;
    int32 Seed;
    FGuid SavegameID;
    bool CanAbort;
    bool CanSkip;
    FText TitlePrefix;
    FText Title;
    FText DescriptionHeader;
    FText Description;
    FText RewardText;
    FText RewardFlavorText;
    TSoftObjectPtr<UTexture2D> Picture;
    ECampaignType campaigntype;
    UMissionStat* CampaignCompletedMissionStat;
    UGameActivityAssignmentType* CampaignActivity;
    TSubclassOf<UCampaign> ReplacesOldCampaignCampaign;
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ECampaignMutators Mutators;
    UCampaign();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsComplete() const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool IsCampaignComplete(UObject* WorldContext, TSubclassOf<UCampaign> Campaign);
    static UCampaign* GetReference(TSubclassOf<UCampaign> Campaign);
    UCampaignMission* GetPreviousMission() const;
    UTexture2D* GetPicture() const;
    static FText GetCampaignTitle(TSubclassOf<UCampaign> Campaign);
    UCampaignMission* GetActiveMission() const;
    bool CanStartCampaign(AFSDPlayerController* Player) const;
    bool CanSeeCampaign(APlayerController* PlayerController) const;
    bool AreRestrictionsMet(AFSDPlayerController* Player, UDifficultySetting* optionalDifficulty) const;
};
