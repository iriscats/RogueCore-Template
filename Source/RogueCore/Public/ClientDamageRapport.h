#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "NetDamageInstance.h"
#include "ClientDamageRapport.generated.h"

class AActor;
class APawn;
class UFSDPhysicalMaterial;
class UPrimitiveComponent;
USTRUCT(BlueprintType)
struct FClientDamageRapport {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNetDamageInstance> Instances;
    
    FVector_NetQuantize Location;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* HitComponent;
    UFSDPhysicalMaterial* PhysMat;
    AActor* DamageCauser;
    APawn* Instigator;
    AActor* Target;
    int32 BoneIndex;
    float BaseDamage;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 CritLevel;
    ROGUECORE_API FClientDamageRapport();
};
