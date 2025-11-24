#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "NetRadialDamageInstance.h"
#include "ClientRadialDamageRapport.generated.h"

class AActor;
class APawn;
USTRUCT(BlueprintType)
struct FClientRadialDamageRapport {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNetRadialDamageInstance> Instances;
    
    AActor* DamageCauser;
    APawn* Instigator;
    FVector_NetQuantize Location;
    float BaseDamage;
    float RadialRadius;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 CritLevel;
    bool Notify;
    ROGUECORE_API FClientRadialDamageRapport();
};
