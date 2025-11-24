#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"

#include "Engine/NetSerialization.h"
#include "Templates/SubclassOf.h"
#include "StickyFlameSpawner.generated.h"

class AStickyFlame;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UStickyFlameSpawner : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStickyFlameSignature, AStickyFlame*, StickyFlame);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStickyFlameSignature OnStickyFlameSpawned;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AStickyFlame> StickyFlameActor;
    float FlameLifetime;
    float StickyFlameIntervals;
    float StickyMaxSpawnPerSecond;
    float StickyFlameMinDistance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StickyFlameLastTime;
    FVector StickyFlameLastLocation;
    UStickyFlameSpawner(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool TrySpawnStickyFlameHit(const FHitResult& Hit);
    bool TrySpawnStickyFlame(FVector Location, FVector Normal);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSpawnStickyFlame(FVector_NetQuantize Location, FVector_NetQuantizeNormal Normal);
};
