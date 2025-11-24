#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "DoubleDrillDamageItem.generated.h"

class UFSDPhysicalMaterial;
class UPrimitiveComponent;
USTRUCT(BlueprintType)
struct FDoubleDrillDamageItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize Location;
    FVector_NetQuantizeNormal Normal;
    UFSDPhysicalMaterial* Material;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NotReplicated, meta=(AllowPrivateAccess=true))
    FName BoneName;
    uint8 BoneIndex;
    ROGUECORE_API FDoubleDrillDamageItem();
};
