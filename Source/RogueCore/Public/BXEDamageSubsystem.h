#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AsyncRadialData.h"
#include "DamageInstance.h"
#include "DamageParams.h"
#include "PrefetchedData.h"
#include "BXEDamageSubsystem.generated.h"

class AActor;
class UDamageAsset;
class UObject;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API UBXEDamageSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section


public:
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAsyncRadialData> AsyncData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CriticalDamageMultiplier;
    UBXEDamageSubsystem();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static FPrefetchedData PrefetchDamageCondition(AActor* FromActor, const TArray<FDamageInstance>& DamageInstance);
    UFUNCTION(BlueprintCallable)
    float Local_DamageTargetWithInstances(const TArray<FDamageInstance>& damageInstances, const FDamageParams& Params);
    float Local_DamageTargetWithInstance(const FDamageInstance& DamageInstance, const FDamageParams& Params);
    float Local_DamageTarget(UDamageAsset* DamageAsset, const FDamageParams& Params, FPrefetchedData prefetchedResults);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContext"))
    static float DamageTargetWithInstances(UObject* WorldContext, const TArray<FDamageInstance>& Instances, const FDamageParams& Params, FPrefetchedData prefetchedResults);
    static float DamageTargetWithInstance(UObject* WorldContext, const FDamageInstance& instance, const FDamageParams& Params, FPrefetchedData prefetchedResults);
    static float DamageTarget(UObject* WorldContext, UDamageAsset* DamageAsset, const FDamageParams& Params, FPrefetchedData prefetchedResults);
};
