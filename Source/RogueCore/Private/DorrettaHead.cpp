#include "DorrettaHead.h"
#include "CarriableComponent.h"
#include "CarriableInstantUsable.h"

ADorrettaHead::ADorrettaHead(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->usable = CreateDefaultSubobject<UCarriableInstantUsable>(TEXT("usable"));
    this->CarriableComponent = CreateDefaultSubobject<UCarriableComponent>(TEXT("CarriableComponent"));
}


