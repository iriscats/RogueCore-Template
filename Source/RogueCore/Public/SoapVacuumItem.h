#pragma once
#include "CoreMinimal.h"

#include "PlagueCleanerResourceChangedDelegate.h"
#include "PlagueCleanupItem.h"
#include "SoapVacuumItem.generated.h"

class AActor;
class UCapsuleComponent;
class UNiagaraComponent;
class UPrimitiveComponent;
class USceneComponent;
UCLASS(Blueprintable)
class ASoapVacuumItem : public APlagueCleanupItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* VacuumCapsule;
    
    UNiagaraComponent* NS_Vacuum_FP;
    UNiagaraComponent* NS_Vacuum_TP;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlagueCleanerResourceChanged OnCurrentVolumeChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VacuumCooldown;
    float VacuumRadius;
    float VacuumRange;
    float CurrentVacuumEffectStrenght;
    float MaxVacuumEffectStrength;
    float VacuumEffectFoamSuckTime;
    float LastPuddleSuckTime;
    ASoapVacuumItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_StartVacuumingPuddle(AActor* Target);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFoamPuddleCollected_Unreliable();
    UFUNCTION(BlueprintCallable)
    void ItemEnterVacuum(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USceneComponent* GetVacuumSource() const;
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_Visual_PuddleStartCollect();
};
