#pragma once
#include "CoreMinimal.h"
#include "EnemyPawn.h"
#include "ParasiteEnemy.generated.h"

class UFXSystemAsset;
class UHealthComponentBase;
class UOutlineComponent;
class USceneComponent;
class USkeletalMeshComponent;
class USoundBase;
class UStaticMeshComponent;
UCLASS(Blueprintable)
class AParasiteEnemy : public AEnemyPawn {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USkeletalMeshComponent* mesh;
    UStaticMeshComponent* Tentacles1;
    UStaticMeshComponent* Tentacles2;
    UOutlineComponent* Outline;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* deathParticles;
    USoundBase* deathSound;
    AParasiteEnemy(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnSelfDeath(UHealthComponentBase* aHealthComponent);
};
