#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ESnapToDirection.h"
#include "GeneratorLine.generated.h"

class UMaterialInterface;
class USplineComponent;
class USplineDecoratorComponent;
class USplineMeshComponent;
class UStaticMesh;
UCLASS(Blueprintable, NoExport)
class AGeneratorLine : public AActor {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    USplineDecoratorComponent* SplineDecorator;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStaticMesh* MeshInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform StartTransform;
    TArray<FTransform> EndTransforms;
    float HeightOffsetMin;
    float HeightOffsetMax;
    float MaxSegmentLength;
    float CarveRadius;
    FVector2D SplineThicknessScale;
    TSoftObjectPtr<UStaticMesh> LineMeshPtr;
    TSoftObjectPtr<UMaterialInterface> MaterialConnected;
    TSoftObjectPtr<UMaterialInterface> MaterialUnconnected;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Path, meta=(AllowPrivateAccess=true))
    TArray<FVector> ReplicatedPath;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ESnapToDirection SnapDirection;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Connected, meta=(AllowPrivateAccess=true))
    bool Connected;
    int32 DecoratorLightMaterialSlot;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USplineMeshComponent*> SplinesThatNeedStaticMeshUpdate;
    AGeneratorLine(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetConnected(bool InConnected);
    UFUNCTION(BlueprintCallable)
    void OnRep_Path();
    UFUNCTION()
    void OnRep_Connected();
};
