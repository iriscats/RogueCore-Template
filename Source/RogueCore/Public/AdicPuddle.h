#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Templates/SubclassOf.h"
#include "AdicPuddle.generated.h"

class APlayerCharacter;
class UPrimitiveComponent;
class USoundBase;
class USphereComponent;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class AAdicPuddle : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> TriggerCollider;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* SphereTrigger;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* SpawnSound;
 
    TSubclassOf<UStatusEffect> InflictedStatusEffect;

    float Lifetime;
    AAdicPuddle(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_OnPlayerBeginOverlap(APlayerCharacter* Player);
    UFUNCTION(BlueprintCallable)
    void OnPuddleEndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnPuddleBeginOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
