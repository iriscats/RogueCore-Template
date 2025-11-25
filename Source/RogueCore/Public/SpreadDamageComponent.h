#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageInstance.h"
#include "SpreadDamageComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API USpreadDamageComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<AActor*, float> DamageLog;
    
    float Range;
    float SpreadDamageMultiplier;
    FDamageInstance DamageInstance;
    USpreadDamageComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DamagedActor(AActor* Target, float amount);
};
