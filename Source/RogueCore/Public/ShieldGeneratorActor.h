#pragma once
#include "CoreMinimal.h"
#include "ThrowableActor.h"
#include "ShieldGeneratorActor.generated.h"

UCLASS(Blueprintable)
class AShieldGeneratorActor : public AThrowableActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float GeneratorRadius;
    
    float DeployDelay;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPushStatusEffectOnExit;
    float GeneratorLifetime;
    AShieldGeneratorActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
