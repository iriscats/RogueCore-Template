#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BXEUnlockCollection.h"
#include "BioBoosterDeckEntry.h"
#include "RewardDispenserReward.h"
#include "BioBoosterDeck.generated.h"

class UBXEUnlockBase;
class UPlayerCharacterID;
class UTexture2D;
class UWorld;
UCLASS(Blueprintable)
class ROGUECORE_API UBioBoosterDeck : public UBXEUnlockCollection {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayerCharacterID* BelongsToClass;
    
    FText Name;
    UTexture2D* Icon;
    TArray<FBioBoosterDeckEntry> Cards;
    TArray<FBioBoosterDeckEntry> SelectableCards;
    TSet<UBXEUnlockBase*> Unlocks;
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableDangerousSaveGameIDEditing;
    FGuid SavegameID;
    UBioBoosterDeck();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FRewardDispenserReward> GetRandomRewardUnlocks(int32 InCount, UWorld* Context, FRandomStream& InRandomStream);
};
