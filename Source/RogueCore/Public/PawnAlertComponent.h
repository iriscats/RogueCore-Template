#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageData.h"
#include "DelegateDelegate.h"
#include "PawnAlertComponent.generated.h"

class APawn;
class UHealthComponentBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPawnAlertComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnAlertedFromDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoAlertAI;
    bool ShouldAlertNearby;
    float AlertRadius;
    UPawnAlertComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopAutoAlerting();
protected:
    void OnPawnSeen(APawn* Pawn);
    void OnHit(float Damage, const FDamageData& DamageData, bool anyHealthLost, UHealthComponentBase* HealthComponent);
    void OnAlerted();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AleartNearby();
};
