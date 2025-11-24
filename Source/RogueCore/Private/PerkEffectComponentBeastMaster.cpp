#include "PerkEffectComponentBeastMaster.h"
#include "Templates/SubclassOf.h"

UPerkEffectComponentBeastMaster::UPerkEffectComponentBeastMaster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShowCanCharmIcon = false;
}

void UPerkEffectComponentBeastMaster::SetDamage(UDamageComponent* cmp, float dmg) {
}

UActorComponent* UPerkEffectComponentBeastMaster::AddPetComponent(TSubclassOf<UActorComponent> ComponentClass, AFSDPawn* targetPet, APlayerCharacter* petOwner) {
    return NULL;
}


