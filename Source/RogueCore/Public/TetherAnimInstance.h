#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TetherAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UTetherAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool SearchingForConnection;
    
    UTetherAnimInstance();
};
