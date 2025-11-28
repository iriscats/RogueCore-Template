#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "BodyRotationManagerComponent.generated.h"

class USceneComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBodyRotationManagerComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve KnockBackCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> RotationComponent;
    float LerpSpeed;
    UBodyRotationManagerComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ApplyKnockBack(float Force, float Duration, const FVector& Direction);
};
