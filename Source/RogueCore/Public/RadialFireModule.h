#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HostileGuntowerModule.h"
#include "Templates/SubclassOf.h"
#include "RadialFireModule.generated.h"

class AProjectile;
UCLASS(Blueprintable, NoExport)
class ARadialFireModule : public AHostileGuntowerModule {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))

    bool IsAttacking;

    FName LeftFireSocket;

    FName RightFireSocket;

    FName FrontFireSocket;

    FName BackFireSocket;

    ARadialFireModule(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectile> ProjectileClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator AttackEndRotation;
    float RotationSpeedTurret;
    float DelayBetweenShots;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IsAttacking;
    FName LeftFireSocket;
    FName RightFireSocket;
    FName FrontFireSocket;
    FName BackFireSocket;
    ARadialFireModule(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFire();
};
