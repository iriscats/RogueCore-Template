#pragma once
#include "CoreMinimal.h"

#include "TowerEventModule.h"
#include "AimingTowerEventModule.generated.h"

class AActor;
UCLASS(Blueprintable)
class AAimingTowerEventModule : public ATowerEventModule {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator AimRotation;

 
    AActor* CurrentTarget;
    AAimingTowerEventModule(const FObjectInitializer& ObjectInitializer);
};
