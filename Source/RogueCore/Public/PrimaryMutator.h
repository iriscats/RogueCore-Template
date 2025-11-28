#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "PrimaryMutator.generated.h"

class UMutator;
class URiskVector;
class UStageLogic;
class UTexture2D;
UCLASS(Blueprintable)
class UPrimaryMutator : public UDataAsset {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStageLogic> StageLogic;
    
    TArray<UMutator*> Mutators;
    TArray<URiskVector*> RiskVectors;
    float HazardBonus;
    bool ShowInUserInterface;
    FText Title;
    FText RichDescription;
    UTexture2D* Icon;
    UPrimaryMutator();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<URiskVector*> GetRiskVectors();
    TArray<UMutator*> GetMutators();
};
