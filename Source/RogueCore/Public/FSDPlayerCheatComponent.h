#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FSDPlayerCheatComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UFSDPlayerCheatComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UFSDPlayerCheatComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void SetHealth(float newHealthValue);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void SetArmor(float NewArmorValue);
    void SetArmor_Implementation(float NewArmorValue);
};
