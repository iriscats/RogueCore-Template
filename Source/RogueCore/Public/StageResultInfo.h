#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StageResultInfo.generated.h"

class UTexture2D;
UCLASS(Blueprintable)
class UStageResultInfo : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasInfo;
    
    float MissionTime;
    float MissionTotalHazBonus;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FText MissionHazName;
    float MissionHazBonus;
    float ComplexityBonus;
    int32 ComplexityDots;
    float LenghtBonus;
    int32 LenghtDots;
    TArray<FText> WarningTitles;
    TArray<UTexture2D*> WarningIcons;
    TArray<float> WarningBonusses;
    float TotalCreditsSum;
    float TotalXPSum;
    bool wasSuccess;
    UStageResultInfo();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWarningBonusSum();
};
