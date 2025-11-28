#pragma once
#include "CoreMinimal.h"
#include "EnemyPawn.h"
#include "HydraWeedHealer.generated.h"

class AHydraWeedCore;
UCLASS(Blueprintable)
class AHydraWeedHealer : public AEnemyPawn {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AHydraWeedCore* Core;
    
    AHydraWeedHealer(const FObjectInitializer& ObjectInitializer);
};
