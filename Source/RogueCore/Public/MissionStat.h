#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "EMissionStatType.h"
#include "Templates/SubclassOf.h"
#include "MissionStat.generated.h"

class APlayerCharacter;
class UFSDAchievement;
class UMissionStat;
class UMissionStatCategory;
class UObject;
class UPlayerCharacterID;
class UTexture2D;
UCLASS(Blueprintable)
class UMissionStat : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FGuid SavegameID;

    FText Title;

    UMissionStatCategory* Category;

    UFSDAchievement* StatAchievement;

    EMissionStatType MissionStatType;

    bool DoNotShowInMissionStatView;

    bool ShowAllValuesCombined;

    bool ShowHighestValue;

    UMissionStat();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))

    float SetStatValue(UObject* WorldContext, APlayerCharacter* Character, float amount);

    UFUNCTION(BlueprintCallable, BlueprintPure)

    static FText MissionStatToText(EMissionStatType StatType, float Value);



public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FStatCountChanged, UObject*, WorldContext, UMissionStat*, MissionStat, float, Value, float, change);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStatCountChanged OnCountChanged;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SavegameID;
    FText Title;
    UMissionStatCategory* Category;
    UFSDAchievement* StatAchievement;
    EMissionStatType MissionStatType;
    bool DoNotShowInMissionStatView;
    bool ShowAllValuesCombined;
    bool ShowHighestValue;
    UMissionStat();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    float SetStatValue(UObject* WorldContext, APlayerCharacter* Character, float amount);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText MissionStatToText(EMissionStatType StatType, float Value);
    static void Increment(UObject* WorldContext, UMissionStat* Stat, TSubclassOf<APlayerCharacter> CharacterClass, float amount);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    float GetStatMinCount(UObject* WorldContext);
    float GetStatMaxCount(UObject* WorldContext);
    FText GetStatCountTotalAsText(UObject* WorldContext);
    float GetStatCountTotal(const UObject* WorldContext) const;
    float GetStatCountPct(UObject* WorldContext, TSubclassOf<APlayerCharacter> CharacterClass);
    FText GetStatCountAsText(UObject* WorldContext, UPlayerCharacterID* characterID);
    float GetStatCount(const UObject* WorldContext, const UPlayerCharacterID* characterID) const;
    FString GetSourceTitle();
    FText GetLowestStatCountAsText(UObject* WorldContext);
    UTexture2D* GetIcon() const;
    FText GetHighestStatCountAsText(UObject* WorldContext);
    FText GetCategoryTitle() const;
};
