#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "UObject/UnrealType.h"
#include "ActorDelegateDelegate.h"
#include "BoolDelegateDelegate.h"
#include "DelegateDelegate.h"
#include "MessageBehaviorTreeDelegate.h"
#include "PlayerCharacterDelegateDelegate.h"
#include "FSDAIController.generated.h"

class APlayerCharacter;
UCLASS(Blueprintable)
class AFSDAIController : public AAIController {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMessageBehaviorTree OnMessageBehaviorTreeEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnAlertedEvent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> LOSTraceChannel;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> TargetedPlayer;
    FPlayerCharacterDelegate OnTargetPlayerChanged;
    FActorDelegate OnTargetUpdated;
    FBoolDelegate OnStaggeredChanged;
    AFSDAIController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetStaggered(bool IsStaggered);
    void SetAlerted(bool isAlerted);
    UFUNCTION(BlueprintCallable)
    void ResumeLogic();
    void RegisterBlackboardChanges(const FName& Key);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Recieve_BlackboardValueChanged(const FName& KeyName);
    void PauseLogic();
    void OnAttackingChanged(bool attacking);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool GetIsAlerted() const;
};
