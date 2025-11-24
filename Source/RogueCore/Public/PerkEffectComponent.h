#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PerkEffectComponent.generated.h"

class APlayerCharacter;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPerkEffectComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    float FloatValue;

    

    APlayerCharacter* PlayerCharacter;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float FloatValue;
    
    APlayerCharacter* PlayerCharacter;
    UPerkEffectComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_OnInitialized();
};
