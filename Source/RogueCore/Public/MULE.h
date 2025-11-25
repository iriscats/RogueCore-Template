#pragma once
#include "CoreMinimal.h"
#include "DeepPathfinderCharacter.h"
#include "MULE.generated.h"

class UHealthComponent;
class USimpleObjectInfoComponent;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API AMULE : public ADeepPathfinderCharacter {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHealthComponent* HealthComponent;
    
    USimpleObjectInfoComponent* ObjectInfo;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsDown, meta=(AllowPrivateAccess=true))
    bool IsDown;
    AMULE(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetIsDown(bool NewIsDown);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetControlledByDropShip(bool Control);
    UFUNCTION()
    void OnRep_IsDown();
};
