#pragma once
#include "CoreMinimal.h"

#include "Grenade.h"
#include "PlasmaBoomerang.generated.h"

class AActor;
class UBoxComponent;
class UCurveVector;
class UDamageComponent;
class UPrimitiveComponent;
class USceneComponent;
class UStaticMeshComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class APlasmaBoomerang : public AGrenade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UBoxComponent* Collision;
    UDamageComponent* DamageComponent;
    UStaticMeshComponent* mesh;
    USceneComponent* MeshPivot;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* ArcCurve;
    float StartSmoothTime;
    float RotationSpeed;
    float ArcSpeed;
    float HomingAcceleration;
    bool IsHoming;
    APlasmaBoomerang(const FObjectInitializer& ObjectInitializer);
 
    UFUNCTION(BlueprintCallable)
    void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
