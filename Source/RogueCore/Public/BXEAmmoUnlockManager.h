#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AmmoUnlockItem.h"
#include "BXEAmmoUnlockManager.generated.h"

class AFSDPlayerController;
class AItem;
class APlayerCharacter;
class UBXEAmmoUnlockManager;
UCLASS(Blueprintable)
class UBXEAmmoUnlockManager : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<APlayerCharacter*, FAmmoUnlockItem> Modifiers;
    
    UBXEAmmoUnlockManager();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UBXEAmmoUnlockManager* GetInstance(const UObject* WorldContext);
    UFUNCTION(BlueprintCallable)
    void ClearUnlock(AFSDPlayerController* PlayerController, const float ammoScale);
    void AddModifierToItem(AItem* Item);
    void AddModifier(AFSDPlayerController* PlayerController, const float ammoScale);
};
