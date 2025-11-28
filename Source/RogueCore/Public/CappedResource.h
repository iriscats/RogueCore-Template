#pragma once
#include "CoreMinimal.h"

#include "UObject/Object.h"
#include "ResourceAddedSignatureDelegate.h"
#include "ResourceChangedSignatureDelegate.h"
#include "ResourceFullSignatureDelegate.h"
#include "CappedResource.generated.h"

class UCappedResource;
class UResourceData;
UCLASS(Blueprintable)
class UCappedResource : public UObject {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResourceChangedSignature OnChanged;
    
    FResourceAddedSignature OnIncreased;
    FResourceFullSignature OnFull;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    UResourceData* Data;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentAmount, meta=(AllowPrivateAccess=true))
    float CurrentAmount;
    float MaxAmount;
    float TotalCollected;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_FullFlag, meta=(AllowPrivateAccess=true))
    int32 FullFlag;
    UCappedResource();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    float TransferAll(UCappedResource* Receiver);
    float Transfer(float amount, UCappedResource* Receiver);
    UFUNCTION()
    void OnRep_FullFlag(int32 OldValue);
    UFUNCTION()
    void OnRep_CurrentAmount(float OldAmount);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsObjectiveResource(UObject* WorldContext, bool& IsCompleted) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFull() const;
    bool IsEmpty() const;
    bool IsCraftingResource() const;
    FText GetTitle() const;
    FColor GetColor() const;
    float GetCapacityPct() const;
    float Deduct(float amount);
    float Add(float amount);
};
