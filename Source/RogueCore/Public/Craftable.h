#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CraftingCost.h"
#include "Craftable.generated.h"

class AFSDPlayerState;
class UObject;
class UPlayerCharacterID;
UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class ROGUECORE_API UCraftable : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API ICraftable : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual void PreviewItem(AFSDPlayerState* PlayerState, bool Show) const PURE_VIRTUAL(PreviewItem,);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    virtual bool IsOwned(UObject* WorldContextObject, UPlayerCharacterID* characterID) const PURE_VIRTUAL(IsOwned, return false;);
    virtual TArray<FCraftingCost> GetResourceCost() const PURE_VIRTUAL(GetResourceCost, return TArray<FCraftingCost>(););
    virtual int32 GetRequiredPlayerRank() const PURE_VIRTUAL(GetRequiredPlayerRank, return 0;);
    virtual FCraftingCost GetFashioniteCost() const PURE_VIRTUAL(GetFashioniteCost, return FCraftingCost{};);
    virtual int32 GetCraftingCreditsCost() const PURE_VIRTUAL(GetCraftingCreditsCost, return 0;);
    virtual FText GetCraftableName() const PURE_VIRTUAL(GetCraftableName, return FText::GetEmpty(););
    virtual FText GetCraftableDescription() const PURE_VIRTUAL(GetCraftableDescription, return FText::GetEmpty(););
    virtual void CraftItemWithFashionite(UObject* WorldContextObject, UPlayerCharacterID* characterID) const PURE_VIRTUAL(CraftItemWithFashionite,);
    virtual void CraftItem(UObject* WorldContextObject, UPlayerCharacterID* characterID) const PURE_VIRTUAL(CraftItem,);
    virtual bool CanCraftWithFashionite(UObject* WorldContextObject) const PURE_VIRTUAL(CanCraftWithFashionite, return false;);
    virtual bool CanCraft(UObject* WorldContextObject) const PURE_VIRTUAL(CanCraft, return false;);
};