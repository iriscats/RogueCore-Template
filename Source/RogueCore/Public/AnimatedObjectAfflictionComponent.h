#pragma once
#include "CoreMinimal.h"
#include "PawnAfflictionComponent.h"
#include "AnimatedObjectAfflictionComponent.generated.h"

class USkeletalMeshComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAnimatedObjectAfflictionComponent : public UPawnAfflictionComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* mesh;
    
    UAnimatedObjectAfflictionComponent(const FObjectInitializer& ObjectInitializer);
};
