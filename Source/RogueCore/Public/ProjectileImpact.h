#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "ProjectileImpact.generated.h"

class UPhysicalMaterial;
class UPrimitiveComponent;
USTRUCT(BlueprintType)
struct FProjectileImpact {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize Location;
    
    FVector_NetQuantizeNormal Normal;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> Component;
    UPhysicalMaterial* PhysMat;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int16 BoneIndex;
    bool bBlockingHit;
    ROGUECORE_API FProjectileImpact();
};
