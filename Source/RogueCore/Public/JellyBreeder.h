#pragma once
#include "CoreMinimal.h"
#include "AFlyingBug.h"
#include "Templates/SubclassOf.h"
#include "JellyBreeder.generated.h"

class AActor;
class AProjectile;
class UAnimSequenceBase;
class UEnemyDescriptor;
class UFXSystemAsset;
class UPhysicalMaterial;
class USoundBase;
UCLASS(Blueprintable)
class AJellyBreeder : public AAFlyingBug {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* EggSpawnAnimation;
    
    UFXSystemAsset* EggParticles;
    USoundBase* EggSound;
    UEnemyDescriptor* EnemyToSpawn;
    TSubclassOf<AProjectile> EggClass;
    float TimeBetweenBursts;
    float TimeBetweenEggs;
    float CloseToSpawnEggTime;
    UPhysicalMaterial* WeakPointMaterial;
    UPhysicalMaterial* UnWeakPointMaterial;
    int32 EggBurstSize;
    int32 MaxJellies;
    float MultiplierOnHighPlayerCount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_BreedMode, meta=(AllowPrivateAccess=true))
    bool IsInBreedMode;
    AJellyBreeder(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SpawnEnemies(AProjectile* egg, int32 AmountToSpawn);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void PlaySpawnEggAnim();
    UFUNCTION()
    void OnRep_BreedMode();
    void OnJellyDestroyed(AActor* aActor);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BreedModeFlipped(bool aIsLayingEggs);
};
