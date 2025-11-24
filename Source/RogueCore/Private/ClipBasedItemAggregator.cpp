#include "ClipBasedItemAggregator.h"

UClipBasedItemAggregator::UClipBasedItemAggregator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShowTotalAmount = true;
    this->ShowClipAndTotalAsOne = false;
}

void UClipBasedItemAggregator::ReloadStarted() {
}

void UClipBasedItemAggregator::ReloadComplete() {
}

int32 UClipBasedItemAggregator::GetReserveCount() const {
    return 0;
}

int32 UClipBasedItemAggregator::GetReserveCapacity() const {
    return 0;
}

int32 UClipBasedItemAggregator::GetClipCount() const {
    return 0;
}

int32 UClipBasedItemAggregator::GetClipCapacity() const {
    return 0;
}


