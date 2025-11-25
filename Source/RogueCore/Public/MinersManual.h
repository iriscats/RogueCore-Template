#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "BiomeFeatures.h"
#include "DamageTypeDescription.h"
#include "EDamageType.h"
#include "MissionStepDescription.h"
#include "MissionTypeDescription.h"
#include "MinersManual.generated.h"

class UBiome;
class UEnemyMinersManualData;
class ULoreScreenMasterWidget;
class UMinersManualData;
class UObject;
class UStageTemplate;
UCLASS(Blueprintable)
class UMinersManual : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ULoreScreenMasterWidget>> BasicsPages;
    
    TMap<int32, FText> BasicsPageHeaders;
    TArray<TSoftClassPtr<ULoreScreenMasterWidget>> CombatPages;
    TArray<TSoftClassPtr<ULoreScreenMasterWidget>> ExtraMissionPages;
    TArray<TSoftClassPtr<ULoreScreenMasterWidget>> ResourcePages;
 
    TArray<UEnemyMinersManualData*> Enemies;
    TArray<TSoftObjectPtr<UBiome>> BiomeReferences;
    TArray<TSoftObjectPtr<UStageTemplate>> MissionReferences;
    TArray<FDamageTypeDescription> DamageTypeInfo;
    TMap<int32, FMissionTypeDescription> MissionDescriptions;
    TMap<int32, FBiomeFeatures> BiomeFeatureDescriptions;
    UMinersManual();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsObjectInMinersManual(UObject* WorldContext, UObject* Object);
    bool IsMissionUnlocked(UObject* WorldContext, UStageTemplate* Mission);
    bool IsBiomeUnlocked(UObject* WorldContext, UBiome* Biome);
    TArray<FText> GetUnlockedCreatureLore(UObject* WorldContext, UEnemyMinersManualData* Enemy, float& completePercentage);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<TSoftObjectPtr<UStageTemplate>> GetMissions() const;
    void GetMissionInfo(int32 MissionTypeIndex, FText& InfoHeadline, FText& InfoDescription, TArray<FMissionStepDescription>& Steps);
    int32 GetEnemyKillCount(UObject* WorldContext, FGuid EnemyID);
    TArray<UEnemyMinersManualData*> GetEnemiesSorted();
    TArray<UEnemyMinersManualData*> GetEnemies();
    void GetDamageTypeDescriptions(TArray<EDamageType> damageTypes, TArray<FDamageTypeDescription>& Icon);
    void GetDamageTypeDescription(EDamageType damageTypes, FDamageTypeDescription& Icon);
    TArray<TSoftObjectPtr<UBiome>> GetBiomes() const;
    TArray<UMinersManualData*> GetBiomeFeatures(int32 BiomeIndex);
    TArray<FDamageTypeDescription> GetAllDamageTypeDescriptions();
};
