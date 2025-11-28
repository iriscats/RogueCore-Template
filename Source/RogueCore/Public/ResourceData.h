#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "SaveGameIDInterface.h"
#include "Templates/SubclassOf.h"
#include "ResourceData.generated.h"

class AFSDPhysicsActor;
class UCappedResource;
class UMissionStat;
class UObject;
class UTexture2D;
UCLASS(Blueprintable)
class ROGUECORE_API UResourceData : public UDataAsset, public ISaveGameIDInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    FText TitlePlural;
    FText Description;
    FColor Color;
    UTexture2D* Icon;
    int32 BuyingPrice;
    int32 SellingPrice;
    UMissionStat* MinedMissionStat;
    TSubclassOf<UCappedResource> CappedResourceTypeOverride;
    bool IsCraftingMaterial;
    bool IsTradable;
    bool ForceShowOnEndScreen;
    bool AffectedByMutators;
    bool IsGymCurrency;
    bool ScaleToMissionLength;
    bool ScaleToHazardLevel;
    bool ShowSeparatelyInEndScreen;
    TSoftClassPtr<AFSDPhysicsActor> Spawnable;
 
    bool IsWholeNumberResource;
    int32 CreditValue;
    int32 XPValue;
    float SeasonXPMultiplier;
    bool AppliesReclaimerPointsMultiplier;
    FGuid SavegameID;
    UResourceData();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    float GetOwnedAmount(const UObject* WorldContextObject) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsTradableCraftingMaterial() const;
    float DeductOwnedAmount(const UObject* WorldContextObject, float amount) const;
    float AddOwnedAmount(const UObject* WorldContextObject, float amount) const;
    // Fix for true pure virtual functions not being implemented
};
