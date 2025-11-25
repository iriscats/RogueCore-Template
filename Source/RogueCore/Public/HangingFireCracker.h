#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HangingFireCracker.generated.h"

class UFSDAudioComponent;
class UInstantUsable;
class UNiagaraComponent;
class UNiagaraSystem;
class USkeletalMeshComponent;
class USoundCue;
class UStaticMeshComponent;
UCLASS(Blueprintable, NoExport)
class AHangingFireCracker : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstantUsable* usable;
    
    USkeletalMeshComponent* SKMesh;
    UNiagaraComponent* MovingSparks;
    UFSDAudioComponent* FuseSound;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> Crackers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* CrackerExplosion;
    USoundCue* CrackerExplosionCue;
    float SparkSpeed;
    float ExplodeRange;
    float ExplodeImpulse;
    AHangingFireCracker(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StartFire();
};
