#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "UObject/UnrealType.h"
#include "CaveVine.generated.h"

class UHealthComponent;
class USceneComponent;
class USplineMeshComponent;
UCLASS(Abstract, Blueprintable)
class ACaveVine : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> GroundCollisionChannel;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineMeshComponent* SplineMeshComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UHealthComponent> Target;
 
    float IdleSwingSpeed;
    float ChaseSpeed;
    float MaxReach;
    float GroundOffset;
    float NoiseRadius;
    float NoiseSpeed;
    USceneComponent* VineHead;
    FVector VineVelocity;
    FVector VineLocation;
    FVector VineStartLocation;
    ACaveVine(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnTargetChanged(UHealthComponent* NewTarget);
    void BP_OnInitialized();
};
