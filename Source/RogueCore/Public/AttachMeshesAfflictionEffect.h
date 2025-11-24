#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "AttachMeshesAfflictionItem.h"
#include "AttachMeshesAfflictionEffect.generated.h"

class UFXSystemAsset;
UCLASS(Blueprintable)
class UAttachMeshesAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAttachMeshesAfflictionItem> AttachItems;
    
    UFXSystemAsset* OnRemoveEffect;
    UAttachMeshesAfflictionEffect();
};
