#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BeamCollision.h"
#include "LockOnBeam.generated.h"

class ALockOnWeapon;
class UMaterialInterface;
class USceneComponent;
class USplineComponent;
class USplineMeshComponent;
UCLASS(Abstract, Blueprintable)
class ALockOnBeam : public AActor {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* BeamSpline;
    
    USplineMeshComponent* BeamMeshComponent01;
    USplineMeshComponent* BeamMeshComponent02;
    USplineMeshComponent* BeamMeshComponent03;
    USceneComponent* BlockedNodeComponent;
    USceneComponent* PreviewLocationComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* BeamMaterial;
    UMaterialInterface* BlockedBeamMaterial;
    UMaterialInterface* SeekerMaterial;
    float BeamThicknessScale;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ALockOnWeapon> Item;
    TWeakObjectPtr<AActor> targetActor;
    FBeamCollision Collision;
    ALockOnBeam(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveItemSet();
};
