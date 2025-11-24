#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GDMilestones.h"
#include "GDMissionStats.h"
#include "KPISettings.generated.h"

UCLASS(Blueprintable)
class UKPISettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGDMissionStats MissionStats;
    
    FGDMilestones Milestones;
    UKPISettings();
};
