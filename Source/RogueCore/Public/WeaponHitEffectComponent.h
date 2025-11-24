#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"

#include "Engine/NetSerialization.h"
#include "Templates/SubclassOf.h"
#include "WeaponHitEffectComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWeaponHitEffectComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EffectChance;
    
    TSubclassOf<AActor> ActorToSpawn;
    UWeaponHitEffectComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SpawnEffect(const FVector_NetQuantize& Location, const FRotator& Rotation);
    UFUNCTION(BlueprintCallable)
    void OnHit(const FHitResult& HitResult, bool isAlwaysPenetrated);
};
