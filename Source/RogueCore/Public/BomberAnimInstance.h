#pragma once
#include "CoreMinimal.h"
#include "FlyingBugAnimInstance.h"
#include "BomberAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UBomberAnimInstance : public UFlyingBugAnimInstance {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ShouldBomb;

    bool ShouldSpiral;
    bool IsBombing;
    bool IsSpiraling;
    UBomberAnimInstance(const FObjectInitializer& ObjectInitializer);
};
