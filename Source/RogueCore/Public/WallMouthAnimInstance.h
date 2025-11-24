#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WallMouthAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UWallMouthAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    bool IsPuking;

    

    UWallMouthAnimInstance();

    UFUNCTION(BlueprintCallable)

    void SetIsPuking(bool InIsPuking);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsPuking;
    
    UWallMouthAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetIsPuking(bool InIsPuking);
};
