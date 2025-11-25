#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "UObject/UnrealType.h"
#include "Components/SplineMeshComponent.h"
#include "BoolDelegateDelegate.h"
#include "CablePathSettings.h"
#include "SplineCableActor.generated.h"

class UMaterialInterface;
class USplineComponent;
class USplineMeshComponent;
class UStaticMesh;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API ASplineCableActor : public AActor {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoolDelegate OnPathCompleted;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* PathSplineComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCablePathSettings PathSettings;
    TSoftObjectPtr<UStaticMesh> CableMesh;
    TEnumAsByte<ESplineMeshAxis::Type> MeshForwardAxis;
    float CableThickness;
    int32 CarveRadius;
    float CarveSurfaceOffset;
    float MaxAllowedPathDistance;
    TSoftObjectPtr<UMaterialInterface> MaterialConnected;
    TSoftObjectPtr<UMaterialInterface> MaterialUnconnected;
    int32 MaterialIndex;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStaticMesh* CableMeshInstance;
    FTransform StartTransform;
    FTransform EndTransform;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Path, meta=(AllowPrivateAccess=true))
    TArray<FVector> ReplicatedPath;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Connected, meta=(AllowPrivateAccess=true))
    bool bConnected;
    bool ClearPointsWhenDone;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USplineMeshComponent*> MeshComponents;
    ASplineCableActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SpawnBetweenTransforms(const FTransform& InStart, const FTransform& InEnd);
    void SetConnected(bool InConnected);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveSegmentCreated(USplineMeshComponent* InSegment, int32 InIndex, int32 InTotal);
    void ReceiveAllSegmentsCreated();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUpdateMaterials();
    UFUNCTION(BlueprintCallable)
    void OnRep_Path();
    UFUNCTION()
    void OnRep_Connected();
};
