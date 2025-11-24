#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PrefetchedDamageBonusResult.h"
#include "PrefetchedDamageBonuses.generated.h"

class UDamageAsset;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UPrefetchedDamageBonuses : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageAsset* DamageAsset;
    
    UPrefetchedDamageBonuses(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FPrefetchedDamageBonusResult GetResult() const;
};
