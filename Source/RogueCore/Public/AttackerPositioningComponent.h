#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "AttackerInfo.h"
#include "AttackerPositioningComponent.generated.h"

class AActor;
class UHealthComponentBase;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAttackerPositioningComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugPositions;
    
    int32 MaxAttackers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAttackerInfo> Attackers;
    TArray<int32> FreePositions;
    TArray<FAttackerInfo> FlyingAttackers;
    TArray<int32> FlyingFreePositions;
    float CharacterPersonalSphere;
    float CharacterHalfHeight;
    float CostModifier;
    UAttackerPositioningComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UnregisterAttacker(AActor* Attacker, bool IsFlying);
    void RegisterAttacker(AActor* Attacker, bool IsFlying);
    void OnFlyingAttackerDeath(UHealthComponentBase* HealthComponent);
    void OnAttackerDeath(UHealthComponentBase* HealthComponent);
    FVector GetFlyingAttackerPosition(AActor* Attacker, float AttackerRadius);
    FVector GetAttackerPosition(AActor* Attacker, float AttackerRadius);
};
