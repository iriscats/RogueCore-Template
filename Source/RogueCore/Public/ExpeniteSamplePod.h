#pragma once
#include "CoreMinimal.h"
#include "RessuplyPod.h"
#include "ExpeniteSamplePod.generated.h"

class UCurveFloat;
UCLASS(Blueprintable)
class AExpeniteSamplePod : public ARessuplyPod {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float ServerReturnProgress;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReturnDelay;
    UCurveFloat* ReturnCurve;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TargetReturnTime;

 
    AExpeniteSamplePod(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void LaunchBackToSpace();
};
