#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/NetSerialization.h"
#include "DamageListener.h"
#include "DamageNumberAggregator.generated.h"

class AActor;
class UDamageClass;
class UFSDPhysicalMaterial;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UDamageNumberAggregator : public UActorComponent, public IDamageListener {
    GENERATED_BODY()
public:
    UDamageNumberAggregator(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void Client_ShowDamageNumber(float Damage, UDamageClass* DamageType, bool Radial, bool isDamageOverTime, AActor* DamageCauser, UFSDPhysicalMaterial* PhysicalMaterial, int32 OverriddenCritLevel, FVector_NetQuantize Location, AActor* Target);

    void Client_ShowArmorDamageNumber_Implementation(float Damage, UDamageClass* DamageType, bool Radial, AActor* DamageCauser, UFSDPhysicalMaterial* PhysicalMaterial, int32 OverriddenCritLevel, FVector_NetQuantize Location, AActor* Target);
    // Fix for true pure virtual functions not being implemented
};
