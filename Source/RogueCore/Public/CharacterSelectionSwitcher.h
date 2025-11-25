#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EVanitySlot.h"
#include "CharacterSelectionSwitcher.generated.h"

class APlayerCharacter;
class UVictoryPose;
UCLASS(Blueprintable)
class ACharacterSelectionSwitcher : public AActor {
    GENERATED_BODY()
public:
    ACharacterSelectionSwitcher(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnVictoryPoseChanged(UVictoryPose* VictoryPose);
    
    void OnVanityItemEquipped(EVanitySlot Slot);
    void Hide();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    AActor* GetViewerActor() const;
    APlayerCharacter* GetActiveCharacter() const;
};
