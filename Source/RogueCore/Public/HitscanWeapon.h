#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "HitscanWeapon.generated.h"

class UHitscanComponent;
UCLASS(Blueprintable, NoExport)
class AHitscanWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitscanComponent* HitscanComponent;
    
    AHitscanWeapon(const FObjectInitializer& ObjectInitializer);
};
