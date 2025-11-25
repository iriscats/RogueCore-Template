#pragma once
#include "CoreMinimal.h"
#include "HitscanBaseComponent.h"
#include "ReflectiveHitscanHit.h"
#include "ReflectionHitscanComponent.generated.h"

class UTerrainType;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UReflectionHitscanComponent : public UHitscanBaseComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainType* PlatformTerrainType;
    
    bool bPlayImpactSound;
    bool bShowImpactOnReflections;
    bool bDamageOnReflections;
    float StraightenReflectionFactor;
    int32 ReflectionCount;
    UReflectionHitscanComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHit_Reflection(const FReflectiveHitscanHit& Hit);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHit(const FReflectiveHitscanHit& Hit);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowHit(const FReflectiveHitscanHit& Hit);
};
