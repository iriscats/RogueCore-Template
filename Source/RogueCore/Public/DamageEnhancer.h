#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "EnhancedTrace.h"
#include "Grenade.h"
#include "Targetable.h"
#include "DamageEnhancer.generated.h"

class AActor;
class UBoxComponent;
class UCapsuleHitscanComponent;
class UDamageComponent;
class UHealthComponent;
class UHitscanBaseComponent;
class UHitscanComponent;
class UPrimitiveComponent;
class UReflectionHitscanComponent;
class USphereComponent;
class UStaticMeshComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ADamageEnhancer : public AGrenade, public ITargetable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* RootCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHealthComponent* HealthComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* DamageComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* mesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* Sphere;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* Box;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitscanComponent* HitscanComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReflectionHitscanComponent* ReflectionHitscanComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleHitscanComponent* CapsuleHitscanComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnhanceDamageBy;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LifetimeMaxDamage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnabledDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceStepTime;
    ADamageEnhancer(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void HitByHitScan(UHitscanBaseComponent* Component, const FVector& Origin, const FHitResult& HitResult);

    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_CompleteTrace(const FEnhancedTrace& trace);
    void BeginOverlapVsProjectile(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_PasteHitScanComponent(UHitscanBaseComponent* HitScan);
    void All_PasteDamageComponent_Implementation(UDamageComponent* Damage);
    // Fix for true pure virtual functions not being implemented
};
