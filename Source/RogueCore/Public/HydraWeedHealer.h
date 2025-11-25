#pragma once
#include "CoreMinimal.h"
#include "EnemyPawn.h"
#include "HydraWeedHealer.generated.h"

class AHydraWeedCore;
UCLASS(Blueprintable, NoExport)
class AHydraWeedHealer : public AEnemyPawn {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AHydraWeedCore* Core;
    
    AHydraWeedHealer(const FObjectInitializer& ObjectInitializer);
};
