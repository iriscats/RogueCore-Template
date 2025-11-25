#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "HitDelegateDelegate.h"
#include "HitscanBaseComponent.h"
#include "HitscanDelayedImpact.h"
#include "IRandRange.h"
#include "HitscanComponent.generated.h"

class AActor;
class UFSDPhysicalMaterial;
class UFXSystemAsset;
class UPrimitiveComponent;
class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UHitscanComponent : public UHitscanBaseComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitDelegate OnHit;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanHitInstigator;
    bool BulletsCanCarve;
    FIRandRange NormalBulletsPerCarvingOne;
    float CarveDiameter;
    float CarveNoise;
    float CarveDebrisSize;
    float GeneralImpactAudioVolume;
    float ImpactDelay;
    bool OnlyUseImpactEffects;
    UFXSystemAsset* ImpactParticles;
    USoundCue* ImpactSound;
    bool IgnoreAlwaysPenetrate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> DamagedActorCache;
    TArray<FHitscanDelayedImpact> DelayedImpacts;
    UHitscanComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterRicochetHit_Terrain(FVector_NetQuantize Origin, FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, UFSDPhysicalMaterial* PhysMaterial, int32 ClipCount);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterRicochetHit_Destructable_Implementation(FVector_NetQuantize Origin, FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, UPrimitiveComponent* Target, UFSDPhysicalMaterial* PhysMaterial, uint8 BoneIndex, int32 ClipCount);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterRicochetHit_Implementation(FVector_NetQuantize Origin, FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, UPrimitiveComponent* Target, UFSDPhysicalMaterial* PhysMaterial, int32 ClipCount, int32 BoneIndex);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHit_Terrain_Implementation(FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, UFSDPhysicalMaterial* PhysMaterial, int32 ClipCount);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHit_Destructable_Implementation(FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, UPrimitiveComponent* Target, UFSDPhysicalMaterial* PhysMaterial, uint8 BoneIndex, int32 ClipCount);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHit_Implementation(FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, UPrimitiveComponent* Target, UFSDPhysicalMaterial* PhysMaterial, int32 ClipCount, int32 BoneIndex);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowRicochetHit_Terrain(FVector_NetQuantize Origin, FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, uint8 MaterialID, UFSDPhysicalMaterial* PhysMaterial);
    UFUNCTION(NetMulticast, Unreliable)
    void All_ShowRicochetHit_Destructable_Implementation(FVector_NetQuantize Origin, FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, UPrimitiveComponent* Target, UFSDPhysicalMaterial* PhysMaterial, uint8 BoneIndex);
    UFUNCTION(NetMulticast, Unreliable)
    void All_ShowRicochetHit_Implementation(FVector_NetQuantize Origin, FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, bool SpawnDecal, UFSDPhysicalMaterial* PhysMaterial);
    UFUNCTION(NetMulticast, Unreliable)
    void All_ShowHit_Terrain_Implementation(FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, uint8 MaterialID, UFSDPhysicalMaterial* PhysMaterial);
    UFUNCTION(NetMulticast, Unreliable)
    void All_ShowHit_Destructable_Implementation(FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, UPrimitiveComponent* Target, UFSDPhysicalMaterial* PhysMaterial, uint8 BoneIndex);
    UFUNCTION(NetMulticast, Unreliable)
    void All_ShowHit_Implementation(FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal, bool SpawnDecal, UFSDPhysicalMaterial* PhysMaterial);
};
