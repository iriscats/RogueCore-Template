#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DelegateDelegate.h"
#include "RewardTreeNode.h"
#include "TreeNodeInteractDelegateDelegate.h"
#include "RewardTreeNodeWidget.generated.h"

class UReward;
class URewardTreeNodeWidget;
UCLASS(Blueprintable, EditInlineNew)
class URewardTreeNodeWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsStartingNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URewardTreeNodeWidget*> ConnectedNodes;
    int32 NodeID;
    int32 Cost;
    bool bIsClickable;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTreeNodeInteractDelegate OnClicked;
    FTreeNodeInteractDelegate OnHover;
    FTreeNodeInteractDelegate OnUnhovered;
    FTreeNodeInteractDelegate OnNodeBought;
    FDelegate IsEditingChanged;
    UReward* Reward;
    bool bIsPlaceholder;
 
    bool IsEditing;
    TArray<UUserWidget*> NodeConnections;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsBought;
    UReward* DefaultReward;
    URewardTreeNodeWidget();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ShowDetailsText(bool InShow);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetSelectedEditor(bool inIsSelected);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIsEditing(bool inIsEditing);
    UFUNCTION(BlueprintCallable)
    void SetIsBought(bool inIsBought);
    void SetData(FRewardTreeNode nodeData);
    void SetConnectedWidgets(TArray<URewardTreeNodeWidget*> inConnectedNodes);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDataUpdated();
    void NodeUnhovered();
    void NodeHovered();
    void NodeClicked();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsBought();
};
