#pragma once
#include "CoreMinimal.h"
#include "RagdollItem.generated.h"

class AActor;
class UMaterialInstanceDynamic;
USTRUCT(BlueprintType)
struct FRagdollItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    TArray<UMaterialInstanceDynamic*> Materials;
    UMaterialInstanceDynamic* DropshadowMaterial;
    ROGUECORE_API FRagdollItem();
};
