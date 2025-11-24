#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VictoryPoseSettings.generated.h"

class UTexture2D;
class UVictoryPose;
UCLASS(Blueprintable)
class UVictoryPoseSettings : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* GenericVictoryPoseIcon;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UVictoryPose*> LoadedVictoryPoses;
    UVictoryPose* RandomVictoryPose;
    UVictoryPoseSettings();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UVictoryPose*> GetVictoryPoses() const;
};
