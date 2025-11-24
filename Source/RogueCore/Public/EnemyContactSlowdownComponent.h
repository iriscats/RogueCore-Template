#pragma once
#include "CoreMinimal.h"

#include "Components/SphereComponent.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "EnemyContactSlowdownComponent.generated.h"

class AActor;
class AEnemyDeepPathfinderCharacter;
class UPrimitiveComponent;
class UStatusEffect;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemyContactSlowdownComponent : public USphereComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    FGameplayTagQuery ValidTargetQuery;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<AEnemyDeepPathfinderCharacter*> ContactList;
    UEnemyContactSlowdownComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool fromSweep, const FHitResult& SweepResult);
};
