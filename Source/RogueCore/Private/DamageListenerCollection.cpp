#include "DamageListenerCollection.h"

UDamageListenerCollection::UDamageListenerCollection(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UDamageListenerCollection::HasDamageBit(int32 BitMask, EDamageListenerQualities bit) {
    return false;
}


