#pragma once
#include "CoreMinimal.h"
#include "EnemyPawn.h"
#include "Templates/SubclassOf.h"
#include "TentaclePlantNode.generated.h"

class ASplineCableActor;
class ATentaclePlant;
class UStaticMeshComponent;
UCLASS(Blueprintable, NoExport)
class ATentaclePlantNode : public AEnemyPawn {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASplineCableActor> TentacleCableType;
    ASplineCableActor* TentacleCable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    ATentaclePlant* TentaclePlant;
    int32 TentacleIndex;
    ATentaclePlantNode(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnPathCompleted(bool wasCompleted);
};
