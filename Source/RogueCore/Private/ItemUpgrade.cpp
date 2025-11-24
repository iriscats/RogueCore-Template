#include "ItemUpgrade.h"
#include "Templates/SubclassOf.h"

UItemUpgrade::UItemUpgrade() {
    this->SelectionFilter = NULL;
    this->Cost = 0;
    this->ModifierType = EWeaponOverviewModifierType::Additive;
    this->UseOldCost = false;
    this->UpgradeTier = EUpgradeTiers::Tier_1;
    this->upgradeClass = EUpgradeClass::Class_A;
    this->Category = NULL;
}

void UItemUpgrade::UnequipUpgrade(TSubclassOf<AActor> itemClass, AFSDPlayerState* PlayerState) {
}

TArray<FItemUpgradeStatText> UItemUpgrade::GetUpgradeStatTexts() const {
    return TArray<FItemUpgradeStatText>();
}

FText UItemUpgrade::GetUpgradeName(UItemUpgrade* upgrade) {
    return FText::GetEmpty();
}

TArray<FCraftingCost> UItemUpgrade::GetUpgradeCost() const {
    return TArray<FCraftingCost>();
}

FString UItemUpgrade::GetSourceName() {
    return TEXT("");
}

bool UItemUpgrade::GetIsAmountPercentage() const {
    return false;
}

FUpgradeValues UItemUpgrade::GetGenericUpgradedValue(TSubclassOf<AActor> Item, AFSDPlayerState* Player, UItemUpgrade* NewUpgradeClass) {
    return FUpgradeValues{};
}

float UItemUpgrade::GetCreditsCost() const {
    return 0.0f;
}

float UItemUpgrade::GetAmount() const {
    return 0.0f;
}

void UItemUpgrade::EquipUpgrade(TSubclassOf<AActor> itemClass, AFSDPlayerState* PlayerState) {
}


