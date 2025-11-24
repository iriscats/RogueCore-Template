#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ECampaignMutators.h"
#include "RequiredMissionItem.h"
#include "CampaignMission.generated.h"

class UDialogDataAsset;
class UPlanetZone;
class UReward;
class URiskVector;
class UStageTemplate;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UCampaignMission : public UDataAsset {
    GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlanetZone* PlanetZone;

    FRequiredMissionItem Mission;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UReward*> Rewards;

    UDialogDataAsset* MissionCompleteShout;

    bool OverrideMutators;

    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ECampaignMutators MutatorOverride;

    TArray<URiskVector*> AllowedRiskVectors;

public:
    UCampaignMission();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStageTemplate* GetMissionTemplate() const;
};
