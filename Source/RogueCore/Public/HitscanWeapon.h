#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "HitscanWeapon.generated.h"

class UHitscanComponent;
UCLASS(Blueprintable)
class AHitscanWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitscanComponent* HitscanComponent;
    
    AHitscanWeapon(const FObjectInitializer& ObjectInitializer);
};
