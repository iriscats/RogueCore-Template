#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NewPlayerMutator.h"
#include "FSDTutorialSettings.generated.h"

UCLASS(Blueprintable)
class UFSDTutorialSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredCPTreasures;
    
    int32 RequiredCPMachineEvents;
    int32 RequiredCPVeterans;
    TArray<FNewPlayerMutator> FirstMissionsMutators;
    UFSDTutorialSettings();
};
