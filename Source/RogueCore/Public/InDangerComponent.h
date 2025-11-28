#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IsInDangerSigDelegate.h"
#include "InDangerComponent.generated.h"

class UHealthComponentBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInDangerComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIsInDangerSig OnInDanger;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UHealthComponentBase> ParentHealthComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageTimeLimit;
    float DamageThreshold;
    bool RunsOnClients;
    UInDangerComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetIsActive(bool aFlag);
    void OnDamage(float amount);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsActive() const;
};
