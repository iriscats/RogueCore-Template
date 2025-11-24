#include "MultiHitscanWeapon.h"
#include "MultiHitscanComponent.h"

AMultiHitscanWeapon::AMultiHitscanWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MultiHitscanComponent = CreateDefaultSubobject<UMultiHitscanComponent>(TEXT("MultiHitScan"));
}


