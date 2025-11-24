#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageEventDelegateDelegate.h"
#include "DamageListenerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDamageListenerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageEventDelegate OnDamageDealt;
    
    FDamageEventDelegate OnKilledTarget;
    FDamageEventDelegate OnCriticalHit;
    UDamageListenerComponent(const FObjectInitializer& ObjectInitializer);
};
