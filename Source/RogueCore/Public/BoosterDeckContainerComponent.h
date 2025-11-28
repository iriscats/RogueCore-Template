#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "RewardDispenserReward.h"
#include "BoosterDeckContainerComponent.generated.h"

class UBioBoosterDeck;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UBoosterDeckContainerComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBioBoosterDeck*> Decks;
    
    FRandomStream RandomStream;
    UBoosterDeckContainerComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    TArray<FRewardDispenserReward> GetRandomCardsFromRandomDeck(int32 count);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UBioBoosterDeck*> GetDecks() const;
};
