#include "RewardTreeLockWidget.h"

URewardTreeLockWidget::URewardTreeLockWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->RequiredForUnlock = 10;
}

bool URewardTreeLockWidget::IsLocked(UObject* WorldContextObject) const {
    return false;
}

int32 URewardTreeLockWidget::GetNumberOfNodesBought(UObject* WorldContextObject) const {
    return 0;
}


