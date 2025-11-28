#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyAnimInstance.h"
#include "TerminatorAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UTerminatorAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator Lean;

    float ForwardLean;
    UTerminatorAnimInstance(const FObjectInitializer& ObjectInitializer);
};
