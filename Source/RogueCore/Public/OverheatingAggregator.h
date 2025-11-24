#pragma once
#include "CoreMinimal.h"
#include "ItemAggregator.h"
#include "OverheatingAggregator.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOverheatingAggregator : public UItemAggregator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOverheatingProgressChanged, float, Progress);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOverheatedChanged, bool, overheated);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOverheatingProgressChanged OnOverheatingProgressChanged;
    FOverheatedChanged OnOverheatedChanged;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float HeatLossPerSecond;
    float OverheatedDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsOverheated, meta=(AllowPrivateAccess=true))
    bool bIsOverheated;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Temperature, meta=(AllowPrivateAccess=true))
    float temperature;
    UOverheatingAggregator(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_SetTemperature(float NewTemperature);
    void Server_SetIsOverheated(bool NewOverheated);
    UFUNCTION(BlueprintCallable)
    void OnRep_Temperature();
    UFUNCTION()
    void OnRep_IsOverheated();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTemperature() const;
    float GetOverheatingProgress() const;
    bool GetIsOverheated() const;
};
