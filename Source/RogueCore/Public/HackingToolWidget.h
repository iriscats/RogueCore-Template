#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HackingToolWidget.generated.h"

class AHackingToolItem;
class UDialogDataAsset;
class UHackingUsableComponent;
class USoundCue;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class ROGUECORE_API UHackingToolWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHackingUnequipDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHackingStageCompletedDelegate, int32, InNextStage, int32, InTotalStages);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHackingFailDelegate, USoundCue*, InFailCue, UDialogDataAsset*, InShout);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHackingCompleteDelegate, bool, InSuccess);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHackingFailDelegate OnHackingFail;
    FHackingStageCompletedDelegate OnHackingStageCompleted;
    FHackingCompleteDelegate OnHackingCompleted;
    FHackingUnequipDelegate OnRequestUnequipHackingTool;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UHackingUsableComponent> HackingUsable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AHackingToolItem> HackingTool;
    UHackingToolWidget();
    UFUNCTION(BlueprintCallable)
    void StartHacking(UHackingUsableComponent* InHackingUsable, AHackingToolItem* InHackingTool);
    void RequestUnequipHackingTool();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveHackingToolUnequipped();
    void ReceiveHackingStarted();
    void ReceiveActionReleased();
    void ReceiveActionPressed();
    void ReceiveActionClick();
    void HackingStageComplete(int32 InNextStage, int32 InTotalStages);
    void HackingComplete(bool InSuccess);
};
