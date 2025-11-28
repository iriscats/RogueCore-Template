#pragma once
#include "CoreMinimal.h"

#include "Subsystems/WorldSubsystem.h"
#include "PerkSubsystem.generated.h"

class UPerkAsset;
class UPerkDelegateItem;
UCLASS(Blueprintable)
class ROGUECORE_API UPerkSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UPerkAsset*, UPerkDelegateItem*> PerkDelegates;
    
    TArray<UPerkAsset*> EnhancementPerks;
    TMap<FGuid, UPerkAsset*> EnhancementPerksMap;
    UPerkSubsystem();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPerkDelegateItem* GetPerkDelegates(UPerkAsset* Perk);
};
