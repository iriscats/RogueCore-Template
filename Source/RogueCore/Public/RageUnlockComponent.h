#pragma once
#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "DamageData.h"
#include "PerkInputUnlockComponent.h"
#include "RageUnlockComponent.generated.h"

class UPlayerHealthComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URageUnlockComponent : public UPerkInputUnlockComponent {
    GENERATED_BODY()

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRageValueChanged, float, Value);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRageComponentDelegate);
    
 
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRageValueChanged OnRageValueChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle RageTimeoutHandle;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeterGainedPerDamageTaken;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RageMeter, meta=(AllowPrivateAccess=true))
    float RageMeterPercent;
    float Duration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool RageOn;
    FRageComponentDelegate OnRageActiveChanged;
    URageUnlockComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void StopRage();
    void StartRage();
    void SetRage(bool rage);
    void RecieveMeter(UPlayerHealthComponent* PHealth, float RawDamage, float actualDamage, const FDamageData& DamageData, bool anyHealthLost);
    UFUNCTION()
    void OnRep_RageOn();
    UFUNCTION()
    void OnRep_RageMeter();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void On_StartRage();
    void On_EndRage();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRageActive() const;
};
