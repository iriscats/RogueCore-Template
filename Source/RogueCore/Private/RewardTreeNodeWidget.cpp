#include "RewardTreeNodeWidget.h"

URewardTreeNodeWidget::URewardTreeNodeWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->bIsStartingNode = false;
    this->NodeID = -1;
    this->Cost = 1;
    this->bIsClickable = false;
    this->Reward = NULL;
    this->bIsPlaceholder = false;
    this->IsEditing = false;
    this->bIsBought = false;
    this->DefaultReward = NULL;
}

void URewardTreeNodeWidget::ShowDetailsText_Implementation(bool InShow) {
}

void URewardTreeNodeWidget::SetIsBought(bool inIsBought) {
}

void URewardTreeNodeWidget::SetData(FRewardTreeNode nodeData) {
}

void URewardTreeNodeWidget::SetConnectedWidgets(TArray<URewardTreeNodeWidget*> inConnectedNodes) {
}


void URewardTreeNodeWidget::NodeUnhovered() {
}

void URewardTreeNodeWidget::NodeHovered() {
}

void URewardTreeNodeWidget::NodeClicked() {
}

bool URewardTreeNodeWidget::GetIsBought() {
    return false;
}


