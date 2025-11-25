#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"

#include "ExplosionBaseComponent.generated.h"

class UDamageComponent;
class UPhysicalMaterial;
class UPrimitiveComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UExplosionBaseComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveDiameterCM;
    
    float CarveNoiseCM;
    float CarveBurnThicknessCM;
    float CarveNormalOffsetCM;
    float CarveNormalSqueeze;
    UExplosionBaseComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void DamageOnlyFromHit(const FHitResult& HitResult, UPARAM(Ref) UDamageComponent*& DamageComponent);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DamageOnly(FVector Location, FName BoneName, UPrimitiveComponent* Target, UPhysicalMaterial* PhysicalMaterial, UPARAM(Ref) UDamageComponent*& DamageComponent);
    void DamageArmorClients(const FHitResult& HitResult, UPARAM(Ref) UDamageComponent*& DamageComponent);
    void DamageAndCarveFromHit(const FHitResult& HitResult, UPARAM(Ref) UDamageComponent*& DamageComponent);
    void DamageAndCarve(FVector Location, FVector ImpactNormal, FName BoneName, UPrimitiveComponent* Target, UPhysicalMaterial* PhysicalMaterial, UPARAM(Ref) UDamageComponent*& DamageComponent);
    void CarveOnly(FVector Location, FVector ImpactNormal);
};
