#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TowerEventModule.h"
#include "AimingTowerEventModule.generated.h"

class AActor;
UCLASS(Blueprintable, NoExport)
class AAimingTowerEventModule : public ATowerEventModule {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator AimRotation;

protected:
    AActor* CurrentTarget;
    AAimingTowerEventModule(const FObjectInitializer& ObjectInitializer);
};
