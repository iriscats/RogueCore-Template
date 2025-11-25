#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExtruderPlant.generated.h"

class UAnimationAsset;
class UAudioComponent;
class USkeletalMeshComponent;
UCLASS(Abstract, Blueprintable)
class AExtruderPlant : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* ExtrudeAnimation;
    UAnimationAsset* RetractAnimation;
    UAudioComponent* Audio;

 
    AExtruderPlant(const FObjectInitializer& ObjectInitializer);
};
