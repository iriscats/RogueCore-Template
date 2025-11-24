#pragma once
#include "CoreMinimal.h"
#include "HitDelegateDelegate.h"
#include "HitscanBaseComponent.h"
#include "MultiHitScanHits.h"
#include "MultiHitscanComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMultiHitscanComponent : public UHitscanBaseComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    TArray<AActor*> DamagedActorCache;

    FMultiHitScanHits Hits;

    TArray<AActor*> ActorsHit;

    UMultiHitscanComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Reliable, Server)

    void Server_RegisterHit(const FMultiHitScanHits& hitResults, int32 Clip);



public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitDelegate OnHit;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BulletsPerShot;
    float GeneralImpactAudioVolume;
    bool CountMultiHits;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> DamagedActorCache;
    FMultiHitScanHits Hits;
    TArray<AActor*> ActorsHit;
    UMultiHitscanComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHit(const FMultiHitScanHits& hitResults, int32 Clip);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowHit(const FMultiHitScanHits& hitResults);
};
