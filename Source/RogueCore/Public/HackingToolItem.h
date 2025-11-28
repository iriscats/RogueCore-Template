#pragma once
#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "HackingToolItem.generated.h"

class UHackingUsableComponent;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API AHackingToolItem : public AAnimatedItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, ReplicatedUsing=OnRep_HackingUsable, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UHackingUsableComponent> HackingUsable;
    
    AHackingToolItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_HackingCompleted(UHackingUsableComponent* InUsable, bool InHackingSuccessful);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveHackingStarted();
    void ReceivedActionReleased();
    void ReceivedActionPressed();
    void ReceiveActionClick();
    UFUNCTION(BlueprintCallable)
    void OnRep_HackingUsable();
    void HackingCompleted(bool InHackingSuccessful);
};
