#pragma once
#include "CoreMinimal.h"
#include "ThrowableActor.h"
#include "ShieldGeneratorActor.generated.h"

UCLASS(Blueprintable, NoExport)
class AShieldGeneratorActor : public AThrowableActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float GeneratorRadius;
    
    float DeployDelay;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPushStatusEffectOnExit;
    float GeneratorLifetime;
    AShieldGeneratorActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
