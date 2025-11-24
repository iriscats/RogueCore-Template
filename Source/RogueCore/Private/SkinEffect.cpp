#include "SkinEffect.h"

USkinEffect::USkinEffect() {
}

void USkinEffect::Receive_AddToItem(UMeshComponent* mesh, AActor* Skinnable, bool IsFirstPerson) const {
}

EItemSkinType USkinEffect::GetSkinType() const {
    return EItemSkinType::PaintJob;
}


