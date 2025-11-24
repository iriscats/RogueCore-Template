#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StairData.h"
#include "DynamicStaircase.generated.h"

class UBoxComponent;
class UInstancedStaticMeshComponent;
class UPathfinderCollisionComponent;
class USceneComponent;
class UStairSettings;
class UStaticMeshComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ADynamicStaircase : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UInstancedStaticMeshComponent* StairBody;
    UStaticMeshComponent* TopSegmentMesh;
    UStaticMeshComponent* BottomSegmentMesh;
    UPathfinderCollisionComponent* PathfinderCollision;
    UPathfinderCollisionComponent* BlockingPathfinderCollision;
    UBoxComponent* StairCollision;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_StairData, meta=(AllowPrivateAccess=true))
    FStairData StairData;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PreviewStairIndex;
    float PreviewStairLenght;
    TArray<UStairSettings*> StairVersions;
    float CollisionOffset;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 SelectedStairVersion;
    ADynamicStaircase(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void WaitForSetup();
    UFUNCTION()
    void OnRep_StairData();
};
