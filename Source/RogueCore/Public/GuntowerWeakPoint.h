#pragma once
#include "CoreMinimal.h"
#include "FSDPawn.h"
#include "GuntowerWeakPoint.generated.h"

class UDamageClass;
class UEnemyHealthComponent;
class UFXSystemAsset;
class USceneComponent;
class USoundCue;
class UStaticMeshComponent;
class UWeakpointGlowComponent;
UCLASS(Blueprintable)
class AGuntowerWeakPoint : public AFSDPawn {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UEnemyHealthComponent* Health;
    UStaticMeshComponent* mesh;
    UWeakpointGlowComponent* HitGlow;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UEnemyHealthComponent> ParentHealth;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* DamageToParent;
    UFXSystemAsset* deathParticles;
    USoundCue* deathSound;
    AGuntowerWeakPoint(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExposedChanged(bool isExposed);
    UFUNCTION(BlueprintCallable)
    void DamageParent(float ammount);
};
