#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageListener.h"
#include "BXELogicUnlockComponent.generated.h"

class APlayerCharacter;
class UWeaponTagBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBXELogicUnlockComponent : public UActorComponent, public IDamageListener {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Stacks, meta=(AllowPrivateAccess=true))
    TArray<float> Stacks;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWeaponTagBase*> ListensForTags;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 DamageListenerProfile;
    bool TriggerBlueprintEvents;
    UBXELogicUnlockComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void Receive_InitializeUnlockLogic();
    void Receive_ClearUnlockForDestroy();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_AddStack(float newStack);
    UFUNCTION(BlueprintCallable)
    void OnRep_Stacks();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalUpgradeValueMultiplied() const;
    float GetTotalUpgradeValue() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetModifierValue(float InAmount) const;
    float GetClampedUpgradeValue(float Previous) const;
    // Fix for true pure virtual functions not being implemented
};
