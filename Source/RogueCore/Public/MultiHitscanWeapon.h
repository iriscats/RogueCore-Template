#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "MultiHitscanWeapon.generated.h"

class UMultiHitscanComponent;
UCLASS(Blueprintable)
class AMultiHitscanWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMultiHitscanComponent* MultiHitscanComponent;
    
    AMultiHitscanWeapon(const FObjectInitializer& ObjectInitializer);
};
