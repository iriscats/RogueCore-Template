#pragma once
#include "CoreMinimal.h"
#include "CoreSpawnEnemyBase.h"
#include "DelegateEventDelegate.h"
#include "SpawnLordAdEnemy.generated.h"

class AActor;
class ASpawnLordEnemy;
class UGrabberComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ASpawnLordAdEnemy : public ACoreSpawnEnemyBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEvent OnUndock;
    
    FDelegateEvent OnDock;
    FDelegateEvent OnGoingHome;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HomeSocketName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool IsDocked;
    bool IsHomeless;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGrabberComponent* Grabber;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASpawnLordEnemy* boss;
    ASpawnLordAdEnemy(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void Undock();
    void OnDamageTaken(float damageTaken);
    bool GrabPlayer(AActor* Target);
    void GoHome();
    void Dock();
};
