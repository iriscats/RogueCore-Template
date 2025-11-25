#pragma once
#include "CoreMinimal.h"
#include "UObject/UnrealType.h"
#include "BioBoosterReward.h"
#include "RewardDispenserBase.h"
#include "BioBoosterTerminal.generated.h"

class APlayerCharacter;
class UBioBoosterDeck;
class UBioBoosterSelectorWidget;
class UBioBoosterTerminalUsable;
class UHackingUsableComponent;
class USkeletalMeshComponent;
class UWidgetComponent;
UCLASS(Blueprintable)
class ROGUECORE_API ABioBoosterTerminal : public ARewardDispenserBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RewardCount;
    
    TArray<FName> VialBoneNames;
    TArray<int32> UsedVialIndices;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    UHackingUsableComponent* HackTerminalUsable;
    UBioBoosterTerminalUsable* PlayerInterfaceUsable;
    UWidgetComponent* PlayerInterfaceWidget;
    UBioBoosterSelectorWidget* SelectorWidget;
    TArray<FBioBoosterReward> AvailableRewards;
    UBioBoosterDeck* BioBoosterDeck;
    ABioBoosterTerminal(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RecieveInterfaceVisibiltyChanged(bool InIsVisible);
    UFUNCTION(BlueprintCallable)
    void OnPlayerInterfaceVisibilityChanged(ESlateVisibility InVisibility);
    void OnPlayerInterfaceUsed(APlayerCharacter* InPlayer);
    void OnPlayerInterfaceUnhovered(APlayerCharacter* InPlayer);
    void OnPlayerInterfaceProgress(float InProgress);
    void OnPlayerInterfaceHovered(APlayerCharacter* InPlayer);
    void OnActivateTerminalUsed(APlayerCharacter* InPlayer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsInterfaceVisible() const;
};
