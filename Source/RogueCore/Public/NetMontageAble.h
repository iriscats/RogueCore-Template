#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NetMontageAble.generated.h"

class UAnimInstance;
class UAnimMontage;
class USkeletalMeshComponent;
UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class ROGUECORE_API UNetMontageAble : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API INetMontageAble : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual float QueueMontage(UAnimMontage* Montage) PURE_VIRTUAL(QueueMontage, return 0.0f;);
    
    virtual USkeletalMeshComponent* GetSkeletalMesh() const PURE_VIRTUAL(GetSkeletalMesh, return NULL;);
    virtual UAnimInstance* GetAnimInstance() const PURE_VIRTUAL(GetAnimInstance, return NULL;);
};
