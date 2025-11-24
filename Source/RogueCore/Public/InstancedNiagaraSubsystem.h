#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Subsystems/WorldSubsystem.h"
#include "InstancedNiagaraSubsystem.generated.h"

class UInstancedNiagaraComponent;
class UNiagaraSystem;
UCLASS(Blueprintable)
class UInstancedNiagaraSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))

    TMap<UNiagaraSystem*, UInstancedNiagaraComponent*> SystemToComponent;

    

    UInstancedNiagaraSubsystem();

    UFUNCTION(BlueprintCallable)

    void SpawnSystemAtLocation(UNiagaraSystem* InSystem, const FVector& InLocation);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<UNiagaraSystem*, UInstancedNiagaraComponent*> SystemToComponent;
    
    UInstancedNiagaraSubsystem();
    UFUNCTION(BlueprintCallable)
    void SpawnSystemAtLocation(UNiagaraSystem* InSystem, const FVector& InLocation);
    void SpawnEmittersAtLocation(UNiagaraSystem* InSystem, const TArray<int32>& InEmitterIndex, const FVector& InLocation);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsInstancingSetUpForSystem(UNiagaraSystem* InSystem);
};
