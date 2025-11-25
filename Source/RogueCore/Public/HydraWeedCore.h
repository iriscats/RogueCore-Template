#pragma once
#include "CoreMinimal.h"
#include "EnemyPawn.h"
#include "HydraWeedCore.generated.h"

class AHydraWeedHealer;
class AHydraWeedShooter;
UCLASS(Blueprintable)
class AHydraWeedCore : public AEnemyPawn {
    GENERATED_BODY()
public:
    AHydraWeedCore(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void WakupCore();
    
    void OnShooterKilled(AHydraWeedShooter* shooter);
    void OnHealerKilled(AHydraWeedHealer* healer);
};
