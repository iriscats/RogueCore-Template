#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "DamageDataBase.generated.h"

class UDamageImpulse;
class UFSDPhysicalMaterial;
class UPrimitiveComponent;
USTRUCT(BlueprintType)
struct FDamageDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFSDPhysicalMaterial* PhysMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> Component;
    FVector_NetQuantize HitLocation;
    int32 BoneIndex;
protected:
    UDamageImpulse* DamageImpulseOverride;
    bool IsRadial;
    int32 CritLevel;
    ROGUECORE_API FDamageDataBase();
};
