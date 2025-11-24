#include "FuelLineBuilderItem.h"
#include "ItemPlacerAggregator.h"

AFuelLineBuilderItem::AFuelLineBuilderItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SegmentPlacer = CreateDefaultSubobject<UItemPlacerAggregator>(TEXT("SegmentPlacer"));
    this->MaxRangeToConnection = -1.00f;
}



