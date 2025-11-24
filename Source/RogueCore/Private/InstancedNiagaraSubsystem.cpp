#include "InstancedNiagaraSubsystem.h"

UInstancedNiagaraSubsystem::UInstancedNiagaraSubsystem() {
}

void UInstancedNiagaraSubsystem::SpawnSystemAtLocation(UNiagaraSystem* InSystem, const FVector& InLocation) {
}

void UInstancedNiagaraSubsystem::SpawnEmittersAtLocation(UNiagaraSystem* InSystem, const TArray<int32>& InEmitterIndex, const FVector& InLocation) {
}

bool UInstancedNiagaraSubsystem::IsInstancingSetUpForSystem(UNiagaraSystem* InSystem) {
    return false;
}


