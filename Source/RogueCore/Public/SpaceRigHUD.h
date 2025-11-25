#pragma once
#include "CoreMinimal.h"
#include "FSDHUD.h"
#include "NotificationEntry.h"
#include "SpaceRigHUD.generated.h"

class UObject;
class UWindowWidget;
UCLASS(Blueprintable, NonTransient)
class ASpaceRigHUD : public AFSDHUD {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FNotificationEntry> NotificationQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNotificationQueueActive;
    ASpaceRigHUD(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetNotificationQueueActive(bool Inactive);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveNotificationQueueActivated();
    void ReceiveNotificationAdded();
    void QueueWindowClass(TSoftClassPtr<UWindowWidget> InWindowType);
    void QueueNotificationObject(UObject* InObject);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNotificationQueueEmpty() const;
    UObject* DequeueNotificationObject();
};
