#pragma once
#include "CoreMinimal.h"
#include "DeepPathfinderCharacter.h"
#include "EDroneState.h"
#include "DroneBase.generated.h"

class UDroneStateComponentBase;
class UPointLightComponent;
UCLASS(Blueprintable)
class ADroneBase : public ADeepPathfinderCharacter {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPointLightComponent* StateLight;

 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDroneState DefaultState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UDroneStateComponentBase*> DroneStates;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentState, meta=(AllowPrivateAccess=true))
    EDroneState CurrentState;

 
    friend struct Z_Construct_UClass_ADroneBase_Statics;
    ADroneBase(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentState(EDroneState Previous);
};
