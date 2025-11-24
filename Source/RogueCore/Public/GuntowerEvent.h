#pragma once
#include "CoreMinimal.h"
#include "GameEvent.h"
#include "GuntowerModuleLevel.h"
#include "GuntowerEvent.generated.h"

class AGuntowerModule;
class UDamageComponent;
class USceneComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class AGuntowerEvent : public AGameEvent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ModuleActive, meta=(AllowPrivateAccess=true))

    int32 ActiveHostileModules;

    AGuntowerEvent(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USkeletalMeshComponent* BaseMesh;
    UDamageComponent* EndExplosionDamage;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGuntowerModuleLevel> GuntowerLevels;
    FName ModuleAttachBone;
    float TowerExplodeDelay;
    float DelayBetweenExplosions;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AGuntowerModule*> TowerModules;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ModuleActive, meta=(AllowPrivateAccess=true))
    int32 ActiveHostileModules;
    AGuntowerEvent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SpawnModules();
    UFUNCTION(BlueprintCallable)
    void OnRep_ModuleActive();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnModulesSpawned();
    void OnModuleExploded(AGuntowerModule* explodedModule);
};
