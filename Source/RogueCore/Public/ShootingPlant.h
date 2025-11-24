#pragma once
#include "CoreMinimal.h"
#include "EnemyPawn.h"
#include "ShootingPlant.generated.h"

class AActor;
UCLASS(Blueprintable, NoExport)
class AShootingPlant : public AEnemyPawn {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IsVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Target, meta=(AllowPrivateAccess=true))
    AActor* Target;
    AShootingPlant(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetTarget(AActor* NewTarget);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRep_Target();
};
