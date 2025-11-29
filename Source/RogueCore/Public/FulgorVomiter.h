#pragma once
#include "CoreMinimal.h"

#include "EnemyPawn.h"
#include "Templates/SubclassOf.h"
#include "FulgorVomiter.generated.h"

class APlayerCharacter;
class AProjectileBase;
class UAnimMontage;
class UHitReactionComponent;
class UOutlineComponent;
class USceneComponent;
UCLASS(Abstract, Blueprintable)
class AFulgorVomiter : public AEnemyPawn {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitReactionComponent* HitReactions;
    
    UOutlineComponent* Outline;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectileBase> VomitProjectile;
    UAnimMontage* VomitMontage;
    float LerpSpeed;
    float Range;
    float Angle;
    float VomitInterval;
    float VomitIntervalReductionForFirstShot;
    bool ShowDebugCone;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FVector TargetDirection;
    USceneComponent* ConeOrigin;

    APlayerCharacter* Target;
    AFulgorVomiter(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void Vomit();
    void OnMontageEnded(UAnimMontage* Montage, bool interrupted);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTarget() const;
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_PlayVomitMontage();
};
