#pragma once
#include "CoreMinimal.h"

#include "UObject/Object.h"
#include "DeepCSGFloatTree.h"
#include "STLMeshCarver.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API USTLMeshCarver : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox AABB;
    
    FDeepCSGFloatTree BSPTree;
    TArray<FVector> Vertices;
    USTLMeshCarver();
};
