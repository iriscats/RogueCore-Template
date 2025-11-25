#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "ECleanedStatus.h"
#include "InfectionPointCleaningComponent.generated.h"

class UDifficultySetting;
class UMeshComponent;
class UNiagaraSystem;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInfectionPointCleaningComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnPointVacuumed;
    
    FDelegate OnPointFoamed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInitialized;
    bool bHasBeenReplicated;
 
    TMap<UDifficultySetting*, int32> DifficultyModifiers;
    UNiagaraSystem* CleanedParticles;
    float particleScale;
    bool outerLayerCleaned;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_InfectionPoints, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<ECleanedStatus>> InfectionPoints;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMeshComponent*> OuterLayerMeshes;
    TArray<UMeshComponent*> InnerLayerMeshes;
    UInfectionPointCleaningComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Reset();
    UFUNCTION(BlueprintCallable)
    void OnRep_InfectionPoints(TArray<TEnumAsByte<ECleanedStatus>> oldInfectionPoints);
    void InitInfectionPoints(const TArray<UMeshComponent*>& outerMeshes, const TArray<UMeshComponent*>& innerMeshes);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRequiredCleanCount() const;
    int32 GetRemainingInfectedPoints() const;
    int32 GetNumberOfInfectedPoints() const;
};
