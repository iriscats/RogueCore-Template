#pragma once
#include "CoreMinimal.h"
#include "EDrinkableAlcoholStrength.h"
#include "SavableDataAsset.h"
#include "DrinkableDataAsset.generated.h"

class ADrinkableActor;
class ADrinkableItem;
class APlayerCharacter;
class UAccessCondition;
class UDLCBase;
class UDialogDataAsset;
class UDrinkEffectComponent;
class UDrinkableDataAsset;
class UMissionStat;
class UObject;
class UResourceData;
class UTemporaryBuff;
class UTexture2D;
UCLASS(Blueprintable)
class UDrinkableDataAsset : public USavableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DrinkableName;
    
    FText DrinkableDescription;
    int32 DrinkablePrice;
    int32 Cost_Sets;
    int32 Cost_Reps;
    bool IsSpecialBeer;
    UAccessCondition* AccessCondition;
    TSoftObjectPtr<UTexture2D> DrinkableIcon;
    int32 RequiredPlayerRank;
    bool ParticipatesInFreeBeerEvent;
    EDrinkableAlcoholStrength AlcoholStrength;
    UDrinkableDataAsset* SpecialEdition;
    UDLCBase* RequiredDLC;
    bool bPlayFireworks;
    UMissionStat* StatConsumed;
    UMissionStat* StatRoundOrdered;
    TSoftClassPtr<ADrinkableActor> DrinkableActorClass;
    TSoftClassPtr<ADrinkableItem> DrinkableItemClass;
    UDialogDataAsset* OrderShout;
    UDialogDataAsset* OrderCheeringShout;
    UDialogDataAsset* DrinkSaluteShout;
    UTemporaryBuff* buff;
    TSoftClassPtr<UDrinkEffectComponent> DrinkEffect;
    TMap<UResourceData*, int32> UnlockCost;
    TMap<UResourceData*, int32> PurchaseCost;
    UDrinkableDataAsset();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static bool TryUnlockSpecialDrinks(UObject* WorldContext);
    bool TryUnlockDrink(UObject* WorldContext);
    bool TryPurchaseDrink(UObject* WorldContext);
    UFUNCTION(BlueprintCallable)
    void OnRoundOrdered(APlayerCharacter* Character);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MustBeUnlocked() const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsUnlocked(UObject* WorldContext) const;
    bool IsDrinkFree(UObject* WorldContext);
    bool HasSpecialEdition() const;
    UDrinkableDataAsset* GetSpecialEdition(UObject* WorldContext);
    UTexture2D* GetDrinkableIcon() const;
    static bool AreSpecialDrinksUnlocked(UObject* WorldContext);
};
