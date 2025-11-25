#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EEnemyHealthScaling.h"
#include "HealthComponent.h"
#include "EnemyHealthComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemyHealthComponent : public UHealthComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyHealthScaling EnemyHealthScaling;
    
 
    float Courage;
    float MaxHealth;
    bool bShowHealthBar;
    FVector HealthBarOffsetWorld;
    bool bIsBossFight;
    int32 BossFightHealthBarSegments;
    bool bRegisterEnemy;
    UEnemyHealthComponent(const FObjectInitializer& ObjectInitializer);
    virtual float GetMaxHealth() const override;
    virtual float GetEnemyDamageResistanceScaling();
};
