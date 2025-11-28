#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemIDInterface.h"
#include "LoadoutItem.h"
#include "SaveGameIDInterface.h"
#include "Templates/SubclassOf.h"
#include "ArmorPiece.generated.h"

class AArmorPiece;
class AItem;
class ALoadoutItemProxy;
class UItemID;
class UPawnStat;
class UUpgradableGearComponent;
UCLASS(Abstract, Blueprintable)
class AArmorPiece : public AActor, public ISaveGameIDInterface, public IItemIDInterface, public ILoadoutItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUpgradableGearComponent* Upgradable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UPawnStat*, float> StatModifiers;
    TSubclassOf<ALoadoutItemProxy> LoadoutProxy;
    UItemID* ItemID;
    TSubclassOf<AActor> WeaponPreviewClass;
    AArmorPiece(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<AActor> GetWeaponViewClass() const;
    static AArmorPiece* GetArmorPieceDefaultObject(TSubclassOf<AArmorPiece> armorPieceClass);
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    TSubclassOf<AItem> GetLoadoutItemClass() const override PURE_VIRTUAL(GetLoadoutItemClass, return NULL;);
};
