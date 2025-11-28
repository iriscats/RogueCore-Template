#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TowerModuleBase.h"
#include "AimingTowerModule.generated.h"

class AActor;
UCLASS(Blueprintable)
class AAimingTowerModule : public ATowerModuleBase {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AActor* Target;

    FRotator AimRotation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BurstTime;

 
    float AttackTime;
    int32 BurstSize;
    AAimingTowerModule(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
