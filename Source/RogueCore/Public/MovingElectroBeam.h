#pragma once
#include "CoreMinimal.h"
#include "ElectroBeam.h"
#include "MovingElectroBeam.generated.h"

class AActor;
UCLASS(Blueprintable, NoExport)
class AMovingElectroBeam : public AElectroBeam {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AActor* Source;
    
    AActor* Target;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    float UpdateRate;
    AMovingElectroBeam(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetTargetActor(AActor* InTarget);
    void SetSourceActor(AActor* InSource);
    void RecalculateMovingBeam();
};
