#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameEvent.h"
#include "Templates/SubclassOf.h"
#include "RivalBomb.generated.h"

class AGem;
class ARivalBombNode;
class UCurveFloat;
class UDebrisPositioning;
UCLASS(Blueprintable)
class ARivalBomb : public AGameEvent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARivalBombNode*> ActiveNodeInstances;
    
    float NodeHackTime;
    int32 NumNodesToHack;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_DataCellPickedUp, meta=(AllowPrivateAccess=true))
    bool bDataCellPickedUp;
    TSubclassOf<AGem> DataCell;
    TSubclassOf<ARivalBombNode> RivalBomb;
    UDebrisPositioning* NodePositioning;
    UCurveFloat* NodeCostCurve;
    ARivalBomb(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void UpdateNodesOnStart();
    void SpawnDataCell();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveDataCellPickedUp();

    UFUNCTION(BlueprintCallable)
    void OnRep_DataCellPickedUp();
    void OnMatchStarted();
    void OnDataCellPickedUp(bool Attached, FVector PrevScale);
    void DeactivateAllNodes(bool Failed);
    void ActivateNewNode();
};
