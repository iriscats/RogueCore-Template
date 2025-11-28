#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerImpactCooldownComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UPlayerImpactCooldownComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolDownTime;
    
    UPlayerImpactCooldownComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool CheckCanImpact(AActor* Actor);
};
