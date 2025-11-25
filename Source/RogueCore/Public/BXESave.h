#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BXEDiveSaveData.h"
#include "BXEMissionStats.h"
#include "BXERunHistory.h"
#include "BXEStartLoadout.h"
#include "IntelCampaignSave.h"
#include "RewardTreeSave.h"
#include "UnlockableItemSave.h"
#include "BXESave.generated.h"

USTRUCT(BlueprintType)
struct FBXESave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBXEStartLoadout StartLoadout;

    FUnlockableItemSave StartingWeapons;
    FBXEMissionStats MissionStats;
    FBXERunHistory RunHistory;
    FIntelCampaignSave CampaignSave;
    bool IsThirdRiskVectorUnlocked;
    ROGUECORE_API FBXESave();
 
    TMap<FGuid, FBXEDiveSaveData> DiveSaves;
    TArray<int32> UnlockedRunDepths;
    int32 EnhancementSlotsUnlocked;
    FRewardTreeSave RewardTreeSave;
    int32 Chips;
    int32 ClaimableChips;
    bool bIsMutatedRunsUnlocked;
};
