#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateDelegate.h"
#include "EventRewardFrame.generated.h"

class AGenericRewardDispenser;
class USpecialEventUsableComponent;
UCLASS(Blueprintable, NoExport)
class AEventRewardFrame : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))

    bool keyInserted;

    TArray<FString> EventPlayerIDs;

    AEventRewardFrame(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpecialEventUsableComponent* EventUsable;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnEventFinishedDelegate;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AGenericRewardDispenser*> Dispensers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool keyInserted;
    TArray<FString> EventPlayerIDs;
    AEventRewardFrame(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void TurnOff();
    void SetKeyInserted(bool NewKeyInserted);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetDispenseRewards(bool dispensRewards);
    void RegisterDispenser(AGenericRewardDispenser* Dispenser);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetDispensRewards() const;
};
