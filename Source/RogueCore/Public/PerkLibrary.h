#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PerkLibrary.generated.h"

class AActor;
class UPerkAsset;
class UPerkComponent;
UCLASS(Blueprintable)
class UPerkLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPerkLibrary();
    UFUNCTION(BlueprintCallable)
    static void SetPerkUseCount(const AActor* Character, const UPerkAsset* Perk, const int32 NewUseCount);
    
    static void SetPerkCooldown(const AActor* Character, const UPerkAsset* Perk, const float NewCooldown);
    static void SetPerkBlocked(const AActor* Character, const UPerkAsset* Perk, const bool IsBlocked);
    static void SetMaximumPerkUses(const AActor* Character, const UPerkAsset* Perk, const int32 MaximumUses);
    static void ResetPerkStates(const AActor* Character);
    static void ResetPerkState(const AActor* Character, const UPerkAsset* Perk);
    static void MarkPerkUsed(const AActor* Character, const UPerkAsset* Perk);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetRemainingPerkUses(const AActor* Character, const UPerkAsset* Perk);
    static int32 GetPerkUseCount(const AActor* Character, const UPerkAsset* Perk);
    static float GetPerkCooldownProgress(const AActor* Character, const UPerkAsset* Perk);
    static float GetPerkCooldown(const AActor* Character, const UPerkAsset* Perk);
    static UPerkComponent* GetPerkComponent(const AActor* Character);
    static int32 GetMaximumPerkUses(const AActor* Character, const UPerkAsset* Perk);
    static TArray<UPerkAsset*> GetActivePerks(const AActor* Character);
    static TArray<UPerkAsset*> GetActiveEnhancementPerks(const AActor* Character);
    static TArray<UPerkAsset*> GetActiveClassPerks(const AActor* Character);
    static bool DoesCharacterHavePerk(const AActor* Character, const UPerkAsset* Perk);
    static bool CanCharacterUsePerk(const AActor* Character, const UPerkAsset* Perk);
};
