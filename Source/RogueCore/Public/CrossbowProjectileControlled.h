#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "CrossbowProjectileControlled.generated.h"

class ACrossbowProjectileBase;
class USceneComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UCrossbowProjectileControlled : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* HomingTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACrossbowProjectileBase* CastedOwner;
    UCrossbowProjectileControlled(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UpdateHomingTarget();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_UpdateHomingTarget(const FVector& Target);
    void CancelControl();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_UpdateHomingTarget(const FVector& Target);
};
