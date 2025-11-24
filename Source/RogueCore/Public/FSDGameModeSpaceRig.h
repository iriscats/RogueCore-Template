#pragma once
#include "CoreMinimal.h"
#include "ESpacerigStartType.h"
#include "FSDGameMode.h"
#include "FSDGameModeSpaceRig.generated.h"

class AActor;
class AFSDPlayerController;
UCLASS(Blueprintable, MinimalAPI, NoExport, NonTransient)
class AFSDGameModeSpaceRig : public AFSDGameMode {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 AmountOfPlayersSpawnedInMedbay;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StartedSession;

protected:
    AFSDGameModeSpaceRig(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnMissionStartedFromSpacerig();
    AActor* GetFreeSpawnOfType(ESpacerigStartType aType, AFSDPlayerController* aController);
};
