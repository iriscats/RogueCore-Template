#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "ShellCrackedSignatureDelegate.h"
#include "EscortDestination.generated.h"

class ADeepCSGWorld;
class UDamageComponent;
class UTerrainMaterial;
UCLASS(Blueprintable)
class ROGUECORE_API AEscortDestination : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FShellCrackedSignature OnShellCracked;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* EndExplosionDamage;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NextBreakpoint;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StageForAnalytics;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 SecondsToDestroyHeartstone;

 
    TArray<float> BreakpointsPercent;
    float Radius;
    float ShellThickness;
    AEscortDestination(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void MeltPlatforms(ADeepCSGWorld* CSGWorld, TArray<FVector> meltPoints, float meltRadius);
    UTerrainMaterial* GetTerrainMaterialByHandle(ADeepCSGWorld* CSGWorld, int32 materialHandle);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSecondsToDestroyObjective();
    FVector GetClosestPointOnRadius(FVector3f CurrentLocation, int32 numberOfShellsCracked, FVector& dirFromCenter);
};
