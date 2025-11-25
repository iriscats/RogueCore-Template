#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorTrackingCheatInterface.h"
#include "DataTerminalBoxEventDelegate.h"
#include "DataTerminalDeviousDataEditorType.h"
#include "DelegateDelegate.h"
#include "EInputKeys.h"
#include "DataTerminal.generated.h"

class APlayerCharacter;
class USceneComponent;
class USingleUsableComponent;
class UUsableComponentBase;
class UUseAnimationSetting;
class UWidgetComponent;
UCLASS(Blueprintable)
class ROGUECORE_API ADataTerminal : public AActor, public IActorTrackingCheatInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_HasBeenActivated, meta=(AllowPrivateAccess=true))
    bool HasBeenActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTerminalBoxEvent OnBoxRepaired;
    FDelegate OnSuccess;
    FDelegate OnBegin;
    FDelegate OnFail;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDataTerminalDeviousDataEditorType> DeviousCharacters;
    int32 MinBaseTextLength;
    int32 MaxBaseTextLength;
    int32 MinNumberTextLength;
    int32 MinBaseTextVariations;
    int32 MaxBaseTextVariations;
    UUseAnimationSetting* AnimationSettings;
    float UseDuration;
    int32 MatchCountRequirement;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USingleUsableComponent*> BoxSingleUsableComponents;
    USceneComponent* Root;
    USceneComponent* BoxColliderContainer;
    USingleUsableComponent* SingleUsable;
    UWidgetComponent* WidgetComponent;
    TArray<FText> BoxTextCollection;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ActiveBoxes, meta=(AllowPrivateAccess=true))
    TArray<int32> ActiveBoxes;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RandomSeed, meta=(AllowPrivateAccess=true))
    int32 RandomSeed;
    ADataTerminal(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ActivateTerminal();
    UFUNCTION(BlueprintCallable)
    void OnRep_RandomSeed();
    UFUNCTION()
    void OnRep_HasBeenActivated();
    UFUNCTION()
    void OnRep_ActiveBoxes(TArray<int32> PrevBoxes);
    void OnCharacterUsed(APlayerCharacter* User, EInputKeys Key);
    void OnBoxUsed(APlayerCharacter* User, EInputKeys Key, UUsableComponentBase* UsableComponent);
    void OnBoxEndUse(UUsableComponentBase* usable);
    void OnBoxBeginUse(APlayerCharacter* User, EInputKeys Key, UUsableComponentBase* UsableComponent);
    void Cheat_Activate();
    // Fix for true pure virtual functions not being implemented
};
