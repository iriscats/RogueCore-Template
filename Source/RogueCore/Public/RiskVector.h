#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EVoteOptionActionType.h"
#include "Templates/SubclassOf.h"
#include "RiskVector.generated.h"

class UMutator;
class UObjective;
class UStageLogic;
class UTexture2D;
UCLASS(Blueprintable)
class URiskVector : public UDataAsset {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UStageLogic> StageLogic;
    
    TSubclassOf<UObjective> OptionalExtraObjective;
    bool DoubleWarning;
    TArray<UMutator*> Mutators;
    bool ShowInUserInterface;
    FText Title;
    FText RichDescription;
    UTexture2D* Icon;
    UTexture2D* CampaignIcon;
    UTexture2D* Header;
    EVoteOptionActionType VoteOptionActionType;
    bool bVoteRepeatable;
    bool bRunPersistent;
    URiskVector();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetRichDescription() const;
};
