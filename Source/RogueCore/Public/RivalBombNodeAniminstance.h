#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInstance.h"
#include "ERivalBombNodeState.h"
#include "RivalBombNodeAniminstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class URivalBombNodeAniminstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    bool IsActive;

    

    bool IsFailed;

    bool isDone;

    FRotator Rotation;

    float StartOffset;

    URivalBombNodeAniminstance();

    UFUNCTION(BlueprintCallable)

    void SetRivalBombNodeState(ERivalBombNodeState NewState);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsActive;
    
    bool IsFailed;
    bool isDone;
    FRotator Rotation;
    float StartOffset;
    URivalBombNodeAniminstance();
    UFUNCTION(BlueprintCallable)
    void SetRivalBombNodeState(ERivalBombNodeState NewState);
};
