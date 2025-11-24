#pragma once
#include "CoreMinimal.h"
#include "UDebrisStaticCarveMesh.generated.h"

class UStaticMeshCarver;
USTRUCT(BlueprintType)
struct FUDebrisStaticCarveMesh {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMeshCarver* mesh;
    
    float Probablity;
    ROGUECORE_API FUDebrisStaticCarveMesh();
};
