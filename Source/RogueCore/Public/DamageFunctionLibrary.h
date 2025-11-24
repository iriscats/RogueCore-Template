#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "DamageData.h"
#include "DamageListenerData.h"
#include "DamageFunctionLibrary.generated.h"

class AActor;
class UDamageClass;
class UDamageImpulse;
class UDamageTag;
class UFSDPhysicalMaterial;
class ULimbDismembermentList;
class UObject;
class UPawnStatsComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable)
class UDamageFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UDamageFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static void SetPhysicalMaterialOnHit(UFSDPhysicalMaterial* PhysMat, UPARAM(Ref) FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsGibbedDeath(const TArray<UDamageTag*>& Tags);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool IsExplosiveDeath(UObject* WorldContext, UPawnStatsComponent* PawnStats, const TArray<UDamageTag*>& Tags);
    static bool IsCorrosiveDeath(UDamageClass* DamageClass, const TArray<UDamageTag*>& Tags);
    static bool IsCookedDeath(const TArray<UDamageTag*>& Tags);
    static bool IsBurnDeath(UDamageClass* DamageClass, const TArray<UDamageTag*>& Tags);
    static FVector GetForceFromDamageImpulse(const AActor*& Target, const FDamageData& DamageData);
    static UDamageImpulse* GetDamageImpulse(const FDamageData& DamageData);
    static int32 FindClosestBoneIndex(const USkeletalMeshComponent*& mesh, const FVector& Location, ULimbDismembermentList* dismembermentList, float MaxDistance);
    static FName FindClosestBone(const USkeletalMeshComponent*& mesh, const FVector& Location, ULimbDismembermentList* dismembermentList, float MaxDistance);
    static bool AnyListenerDataHasDamageTypes(const TArray<FDamageListenerData>& Data, const TArray<UDamageClass*>& DamageClasses);
    static bool AllListenerDataAreDamageTypes(const TArray<FDamageListenerData>& Data, const TArray<UDamageClass*>& DamageClasses);
};
