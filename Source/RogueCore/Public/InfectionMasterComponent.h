#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "InfectionMasterComponent.generated.h"

class UHealthComponent;
class UHealthComponentBase;
class UMaterialInterface;
class UStaticMesh;
class UStaticMeshComponent;
class UStatusEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInfectionMasterComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> WeakpointPopSTE;
    
    float WeakpointPopSTERange;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 InfectionPoints;
    bool ExtraInfectionPointsWithMorePlayers;
    float SpikeScale;
    float InfectionScale;
    bool KillWhenAllPointsDestroyed;
    float ScaleDownOnDeathTime;
    UMaterialInterface* BaseMat;
    UMaterialInterface* GlowMat;
    TArray<UStaticMesh*> InfectionPointMeshes;
    TArray<UStaticMesh*> InfectionSpikeMeshes;
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UHealthComponent* HealthComponent;
    TArray<UStaticMeshComponent*> MeshComponents;
    UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_RandomSeed, meta=(AllowPrivateAccess=true))
    uint32 RandomSeed;
    UInfectionMasterComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_RandomSeed();
    void OnDeath(UHealthComponentBase* Enemy);
    void InfectionPointDestroyed(FName Name);
    void DealWeakpointDamage(const FName& SocketName);
};
