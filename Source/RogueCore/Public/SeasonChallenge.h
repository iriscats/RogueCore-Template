#pragma once
#include "CoreMinimal.h"

#include "ChallengeVariation.h"
#include "SavableDataAsset.h"
#include "Templates/SubclassOf.h"
#include "TrackedStatInfo.h"
#include "SeasonChallenge.generated.h"

class UCampaign;
class USeasonChallenge;
class UTexture2D;
UCLASS(Blueprintable)
class USeasonChallenge : public USavableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ChallengeText;
    
    TSoftObjectPtr<UTexture2D> Icon;
    TSoftObjectPtr<UTexture2D> IconOutlined;
    FLinearColor Color;
    TArray<FTrackedStatInfo> TrackedStats;
    TArray<FChallengeVariation> Variations;
    int32 NumberOfChoices;
    float ChallengeWeight;
    bool bIsSpecialChallenge;
    int32 MaxOccurences;
    USeasonChallenge* ChallengeAfterMaxOccurences;
    TArray<TSubclassOf<UCampaign>> RequiredCampaigns;
    USeasonChallenge();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetIconOutlined();
    UTexture2D* GetIcon();
};
