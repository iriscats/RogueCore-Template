#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CaretakerActionComponent.generated.h"

class ACaretaker;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCaretakerActionComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StartTickOnUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsUsing, meta=(AllowPrivateAccess=true))
    bool isUsing;
    UCaretakerActionComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void UseAction();
    void TriggerAction();
    void StopUsing();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTriggered();
    void OnStopped();
    void OnStarted();
    UFUNCTION(BlueprintCallable)
    void OnRep_IsUsing();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACaretaker* GetCaretaker() const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool CanUse() const;
};
