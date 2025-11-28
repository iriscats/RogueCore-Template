#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInstance.h"
#include "DataTerminalAnimInstance.generated.h"

class ADataTerminal;
class UCurveFloat;
UCLASS(Abstract, Blueprintable, NonTransient)
class UDataTerminalAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ADataTerminal* DataTerminal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* FallingAnimationCurve;
    UCurveFloat* RetractingAnimationCurve;
    float FallAnimationSpeed;
    float RetractAnimationSpeed;
    TArray<FRotator> Rotations;
    TArray<FVector> LightLocations;
    TArray<FVector> LightScaling;
    float BlinksPerSecond;
    UDataTerminalAnimInstance();
    UFUNCTION(BlueprintCallable)
    void OnSuccess();
    void OnFail();
    void OnBoxRepaired(int32 BoxIndex);
    void OnBegin();
};
