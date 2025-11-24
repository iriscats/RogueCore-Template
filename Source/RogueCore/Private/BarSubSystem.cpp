#include "BarSubSystem.h"

UBarSubSystem::UBarSubSystem() {
    this->Bartender = NULL;
}

void UBarSubSystem::SetBartender(AOmegaBartender* aBartender) {
}

bool UBarSubSystem::HasEnoughCurrency(const UObject* WorldContextObject, UResourceData* Currency, int32 amount) {
    return false;
}

bool UBarSubSystem::HasCollectiveResource(const UObject* WorldContextObject, UResourceData* Data) {
    return false;
}

UResourceData* UBarSubSystem::GetGymCurrencyData(const UObject* WorldContextObject, int32 Index) {
    return NULL;
}

int32 UBarSubSystem::GetGymCurrencyAmount(const UObject* WorldContextObject, int32 Index) {
    return 0;
}

int32 UBarSubSystem::GetCollectiveResourceIndex(const UObject* WorldContextObject, UResourceData* Data) {
    return 0;
}

AOmegaBartender* UBarSubSystem::GetBartender() const {
    return NULL;
}

TArray<UResourceData*> UBarSubSystem::GetAllGymCurrencyData(const UObject* WorldContextObject) {
    return TArray<UResourceData*>();
}

TArray<int32> UBarSubSystem::GetAllGymCurrencyAmount(const UObject* WorldContextObject) {
    return TArray<int32>();
}

bool UBarSubSystem::DeductCurrency(const UObject* WorldContextObject, UDrinkableDataAsset* Data) {
    return false;
}

void UBarSubSystem::AddInternalCurrency(const UObject* WorldContextObject, UResourceData* Data, int32 amount) {
}

void UBarSubSystem::AddCurrency(const UObject* WorldContextObject, UResourceData* Currency, int32 amount) {
}


