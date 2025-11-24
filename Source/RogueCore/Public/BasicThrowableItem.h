#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "CarriableItem.h"
#include "EInputKeys.h"
#include "BasicThrowableItem.generated.h"

class AActor;
class APlayerCharacter;
class UBoxComponent;
class UCarriableComponent;
class UFirstPersonStaticMeshComponent;
class UInstantUsable;
class UPrimitiveComponent;
class USoundCue;
class USphereComponent;
class UStaticMeshComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ABasicThrowableItem : public ACarriableItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* BoxComp;
    
    USphereComponent* UseSphere;
    UCarriableComponent* CarriableComp;
    UInstantUsable* UsableComp;
    UStaticMeshComponent* WorldMeshComp;
    UFirstPersonStaticMeshComponent* ViewMeshComp;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ImpactSound;
    float SquaredMinImpactForce;
    float ImpactAudioResetTime;
    float SquaredMinThrowforce;
    ABasicThrowableItem(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void ResetImpactSound();
    void OnUsed(APlayerCharacter* User, EInputKeys Key);
    void OnUsableChanged(bool CanUse);
    void OnPickedUp();
    void OnDropped();
    void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
