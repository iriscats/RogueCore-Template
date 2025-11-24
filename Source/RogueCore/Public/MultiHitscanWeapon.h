#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "MultiHitscanWeapon.generated.h"

class UMultiHitscanComponent;
UCLASS(Blueprintable, NoExport)
class AMultiHitscanWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMultiHitscanComponent* MultiHitscanComponent;
    
    AMultiHitscanWeapon(const FObjectInitializer& ObjectInitializer);
};
