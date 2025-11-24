#include "EnemyPawn.h"
#include "EnemyComponent.h"
#include "EnemyHealthComponent.h"
#include "EnemyPawnAfflictionComponent.h"
#include "Net/UnrealNetwork.h"
#include "PawnStatsComponent.h"

AEnemyPawn::AEnemyPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Health = CreateDefaultSubobject<UEnemyHealthComponent>(TEXT("Health"));
    this->Stats = CreateDefaultSubobject<UPawnStatsComponent>(TEXT("Stats"));
    this->Affliction = CreateDefaultSubobject<UEnemyPawnAfflictionComponent>(TEXT("Affliction"));
    this->Enemy = CreateDefaultSubobject<UEnemyComponent>(TEXT("Enemy"));
}


void AEnemyPawn::OnRep_QueuedMontage() {
}


void AEnemyPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AEnemyPawn, QueuedMontage);
}


