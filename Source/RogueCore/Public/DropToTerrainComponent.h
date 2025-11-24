#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "OnIsFallingToTerrainChangedDelegate.h"
#include "DropToTerrainComponent.generated.h"

class USceneComponent;
class UTerrainDetectComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDropToTerrainComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnIsFallingToTerrainChanged OnFallToTerrainStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StartActive;
    FVector CurrentLocation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_DropTarget, meta=(AllowPrivateAccess=true))
    FVector DropTarget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTerrainDetectComponent*> TerrainPoints;
    float FallVelocity;
    float TerrainTraceMaxDistance;
    int32 ConnectedPoints;
    bool IsDetecting;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsForceDisabled;
    UDropToTerrainComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void StopDropDetection(bool stopFalling);
    void OnTerrainRemoved(USceneComponent* Point);
    UFUNCTION()
    void OnRep_DropTarget();
    void ForceDisable();
    void BeginDropDetection();
};
