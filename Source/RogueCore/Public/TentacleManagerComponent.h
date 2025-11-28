#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "TentacleManagerComponent.generated.h"

class UNiagaraComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTentacleManagerComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UNiagaraComponent> Tentacles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve SpeedCurve;
    FRuntimeFloatCurve ReachCurve;
    FName Param_Speed;
    FName Param_Reach;
    UTentacleManagerComponent(const FObjectInitializer& ObjectInitializer);
};
