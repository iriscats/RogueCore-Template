#pragma once
#include "CoreMinimal.h"
#include "WeakpointChannel.generated.h"

class UFSDPhysicalMaterial;
class UMaterialInstanceDynamic;
USTRUCT(BlueprintType)
struct FWeakpointChannel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFSDPhysicalMaterial* WeakPointMaterial;
    
    int32 BoneIndex;
    UMaterialInstanceDynamic* Mid;
    ROGUECORE_API FWeakpointChannel();
};
