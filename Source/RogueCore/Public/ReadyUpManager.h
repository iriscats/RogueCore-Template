#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EReadyUpStage.h"
#include "ReadyUpParticipant.h"
#include "ReadyUpState.h"
#include "SingleDelegateDelegate.h"
#include "ReadyUpManager.generated.h"

class AFSDPlayerState;
class UReadyUpWindow;
UCLASS(Blueprintable)
class ROGUECORE_API UReadyUpManager : public UObject {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReadyUpEvent);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReadyUpEvent OnReadyUpStarted;
    FReadyUpEvent OnReadyUpFinished;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReadyUpState State;
    FSingleDelegate OnCompletedCallback;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UReadyUpWindow> ReadyUpWindow;
    UReadyUpManager();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StartReadyUp(const FSingleDelegate& OnCompleted);
    UFUNCTION(BlueprintCallable)
    void SetIsReady(const AFSDPlayerState* InPlayerState);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReadyingUp() const;
    EReadyUpStage GetReadyUpStage() const;
    TArray<FReadyUpParticipant> GetReadyUpParticipants() const;
};
