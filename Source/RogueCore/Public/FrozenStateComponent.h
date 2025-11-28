#pragma once
#include "CoreMinimal.h"
#include "CharacterStateComponent.h"
#include "RandRange.h"
#include "FrozenStateComponent.generated.h"

class UElementEventType;
class UElementType;
class UFSDPhysicalMaterial;
class USoundBase;
UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFrozenStateComponent : public UCharacterStateComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange DeFrostAmount;
    
    TSoftObjectPtr<USoundBase> AudioFreeFromIce;
    TSoftObjectPtr<UFSDPhysicalMaterial> IcePhysicalMaterial;
    TSoftObjectPtr<UFSDPhysicalMaterial> DwarfFleshMaterial;
    float SlowAnimationSpeed;
    float HoldToBreakTime;
    UElementType* ElementType;
    UElementEventType* ElementEventTrigger;
    UFrozenStateComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ThawPlayer();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveOnDefrosting();
};
