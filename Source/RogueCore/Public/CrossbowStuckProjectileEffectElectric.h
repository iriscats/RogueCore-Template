#pragma once
#include "CoreMinimal.h"
#include "CrossbowStuckProjectileEffect.h"
#include "Templates/SubclassOf.h"
#include "CrossbowStuckProjectileEffectElectric.generated.h"

class AActor;
class ACrossbowElectroBeam;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCrossbowStuckProjectileEffectElectric : public UCrossbowStuckProjectileEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACrossbowElectroBeam> PlasmaBeamClass;
    
    TSubclassOf<AActor> ElectrocutionActorClass;
    float PlasmaLineMaxRange;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> ElectrocutionActor;
    UCrossbowStuckProjectileEffectElectric(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnElectrocutionActorDestroyed(AActor* Actor);
};
