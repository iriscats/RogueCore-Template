#pragma once
#include "CoreMinimal.h"
#include "PickaxeMeshInstance.generated.h"

class UMeshComponent;
USTRUCT(BlueprintType)
struct FPickaxeMeshInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMeshComponent* FP_Mesh;
    
    UMeshComponent* TP_Mesh;
    ROGUECORE_API FPickaxeMeshInstance();
};
