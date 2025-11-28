#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "ProjectileSpawnData.h"
#include "MultiprojectileSpawner.generated.h"

class AActor;
class UDataAsset;
class UMultiprojectileSpawner;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UMultiprojectileSpawner : public UActorComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FProjectileSpawnData> ProjectileData;
    
    bool ProjectilesIgnoreEachOther;
    UMultiprojectileSpawner(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsFiring() const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Fire(const FVector& Velocity, const FVector& Origin);
    UFUNCTION(BlueprintCallable)
    static UMultiprojectileSpawner* FindMultiProjectileSpawner(AActor* Actor, UDataAsset* RangedAttack);
};
