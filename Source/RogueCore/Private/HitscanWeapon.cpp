#include "HitscanWeapon.h"
#include "HitscanComponent.h"

AHitscanWeapon::AHitscanWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HitscanComponent = CreateDefaultSubobject<UHitscanComponent>(TEXT("HitscanComponent"));
}


