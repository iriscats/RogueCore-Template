#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_HideEquippedItem.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, MinimalAPI)
class UAnimNotifyState_HideEquippedItem : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UAnimNotifyState_HideEquippedItem();
};
