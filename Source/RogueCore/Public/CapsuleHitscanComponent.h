#pragma once
#include "CoreMinimal.h"
#include "HitscanBaseComponent.h"
#include "MultiHitScanHits.h"
#include "OnHitDelegateDelegate.h"
#include "CapsuleHitscanComponent.generated.h"

class AActor;
class ADamageEnhancer;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCapsuleHitscanComponent : public UHitscanBaseComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ADamageEnhancer* DamageEnhancer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHitDelegate OnHitEffect;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHitDelegate OnClosestHit_Client;
protected:
    float Range;
    float Width;
    bool ShowPhysMatImpact;
    bool ShowPhysMatDecal;
    bool PlayPhysMatSound;
    TSet<AActor*> ActorsInCapsule;
    TArray<AActor*> DamagedActorCache;
    TArray<AActor*> ActorsHit;
    FMultiHitScanHits Hits;
    UCapsuleHitscanComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHit(const FMultiHitScanHits& hitResults);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowHit(const FMultiHitScanHits& hitResults);
};
