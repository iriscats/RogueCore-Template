#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AvoidCeilingComponent.generated.h"

class USceneComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAvoidCeilingComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDuckDistance;
    
    float TraceVerticalStart;
    float MinVerticalSpace;
    float DuckSpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* ComponentToMove;
    bool IsDuckingEnabled;
    UAvoidCeilingComponent(const FObjectInitializer& ObjectInitializer);
};
