#pragma once
#include "CoreMinimal.h"
#include "ShootingPlant.h"
#include "Templates/SubclassOf.h"
#include "TentaclePlant.generated.h"

class AEnemyPawn;
class ATentaclePlantNode;
class UDebrisPositioning;
UCLASS(Blueprintable)
class ATentaclePlant : public AShootingPlant {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsVulnerable, meta=(AllowPrivateAccess=true))
    bool IsVulnerable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AmountOfNodes;
    float MinimumDistance;
    float MinDistanceBetweenNodes;
    TSubclassOf<AEnemyPawn> NodeType;
    UDebrisPositioning* NodePositioning;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ATentaclePlantNode*> NodeInstances;
    ATentaclePlant(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_IsVulnerable();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNodeDestroyed(ATentaclePlantNode* InNode);
    void OnNodeDamaged(ATentaclePlantNode* InNode);
    void OnIsVulnerable();
    void DestroyNode(ATentaclePlantNode* Node);
};
