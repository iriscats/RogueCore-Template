#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CopyBoneVisibilityCompleted.generated.h"

UINTERFACE()
class ROGUECORE_API UCopyBoneVisibilityCompleted : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API ICopyBoneVisibilityCompleted : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION()
    virtual void CopyBoneVisibilityCompleted(int32 BoneIndex) PURE_VIRTUAL(CopyBoneVisibilityCompleted,);
    
};