#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EArmorType.h"
#include "EDamageType.h"
#include "EEnemyFamily.h"
#include "EEnemyType.h"
#include "EnemyAttackDescription.h"
#include "EnemyMinersManualStats.h"
#include "EnemyMinersManualData.generated.h"

class AEnemyShowroomItem;
class UAnimSequenceBase;
class UEnemyID;
class UTexture2D;
UCLASS(Blueprintable)
class UEnemyMinersManualData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyID* EnemyID;
    
    FText Name;
    FText RichDescription;
    TArray<FText> GameplayTips;
    EEnemyFamily Family;
    EEnemyType EnemyType;
    TArray<FEnemyAttackDescription> AttackType;
    TArray<FEnemyAttackDescription> SpecialAttacks;
    TArray<UAnimSequenceBase*> AttackAnimations;
    EArmorType ArmorType;
    FText Armor;
    FText Weakpoint;
    FEnemyMinersManualStats EnemyStats;
    TArray<EDamageType> Resistances;
    TArray<EDamageType> Weaknesses;
    TArray<FText> LoreInfo;
    bool AlwaysUnlocked;
    int32 InfoUnlockSpeed;
 
    TSoftObjectPtr<UTexture2D> EnemyIcon;
    TSoftClassPtr<AEnemyShowroomItem> PreviewActor;
    UEnemyMinersManualData();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetEnemyIcon() const;
};
