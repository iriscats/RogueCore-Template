#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerRewinderGhost.generated.h"

class UAnimSequence;
class UMaterialInterface;
class USceneComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class ATimerRewinderGhost : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    UMaterialInterface* HologramMaterial;

    UAnimSequence* HologramAnimation;

    FName BoneToScaleToZero;

    ATimerRewinderGhost(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USkeletalMeshComponent* CharacterMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* HologramMaterial;
    UAnimSequence* HologramAnimation;
    FName BoneToScaleToZero;
    ATimerRewinderGhost(const FObjectInitializer& ObjectInitializer);
};
