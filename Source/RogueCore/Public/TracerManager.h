#pragma once
#include "CoreMinimal.h"

#include "Subsystems/WorldSubsystem.h"
#include "TracerManager.generated.h"

class UNiagaraSystem;
UCLASS(Abstract, Blueprintable)
class UTracerManager : public UWorldSubsystem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartScale;
    
    float WhizByStartDistance;
    float WhizByMaxDistanceFromTrajectory;
    float WhizBySpeed;
    UTracerManager();
    UFUNCTION(BlueprintCallable)
    void AddTracer(FVector Origin, const FVector& Destination, float Speed, UNiagaraSystem* particle, float MinDistance, float Offset, UNiagaraSystem* Trail);
};
