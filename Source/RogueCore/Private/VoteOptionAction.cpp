#include "VoteOptionAction.h"

UVoteOptionAction::UVoteOptionAction() {
}

bool UVoteOptionAction::IsRunPersistent() const {
    return false;
}

EVoteOptionActionType UVoteOptionAction::GetVoteOptionActionType() const {
    return EVoteOptionActionType::NEGATIVE;
}

FText UVoteOptionAction::GetTitle() const {
    return FText::GetEmpty();
}

UTexture2D* UVoteOptionAction::GetIcon() const {
    return NULL;
}

FText UVoteOptionAction::GetDescription() const {
    return FText::GetEmpty();
}

void UVoteOptionAction::ApplyAction(AFSDPlayerState* InPlayerState) const {
}


