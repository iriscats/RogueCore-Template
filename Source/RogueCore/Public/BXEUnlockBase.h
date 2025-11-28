#pragma once
#include "CoreMinimal.h"
#include "EProductionStatus.h"
#include "EUnlockType.h"
#include "SavablePrimaryDataAsset.h"
#include "BXEUnlockBase.generated.h"

class UBXEUnlockCategory;
class UBXEUnlockConditionBase;
class UBXEUnlockRarity;
class UDialogDataAsset;
class UTexture2D;
class UUnlockVisualSettings;
class UWeaponTagBase;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API UBXEUnlockBase : public USavablePrimaryDataAsset {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBXEUnlockCategory*> Categories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UBXEUnlockConditionBase*> SelectionConditions;
    bool UnlockUsesRandomRarity;
    UDialogDataAsset* ShoutNegotiationSelected;
 
    UBXEUnlockRarity* DefaultRarity;
    UUnlockVisualSettings* VisualSettingsOverride;
    EUnlockType UnlockType;
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EProductionStatus LogicStatus;
    EProductionStatus ParticleStatus;
    EProductionStatus SoundStatus;
    UBXEUnlockBase();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UUnlockVisualSettings* GetVisualSettings(UBXEUnlockRarity* InRarity) const;
    EUnlockType GetUnlockType() const;
    FText GetTitle() const;
    TArray<UWeaponTagBase*> GetRelatedWeaponTags() const;
    TSoftObjectPtr<UTexture2D> GetIcon() const;
    FText GetDescription() const;
};
