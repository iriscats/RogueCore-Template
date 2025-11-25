#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnDebugComponent.generated.h"

class UHealthComponent;
class UHealthComponentBase;
class UObjectInfoComponent;
class UWidgetComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPawnDebugComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWidgetComponent* WidgetComponent;
    
    UHealthComponent* HealthComponent;
    UObjectInfoComponent* InfoComponent;
    UPawnDebugComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ShowPawnHealth(bool InWidgetVisible);
    void OnHealthChanged(float InValue);
    void OnDeath(UHealthComponentBase* InHealthComponent);
};
