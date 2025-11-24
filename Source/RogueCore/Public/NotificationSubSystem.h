#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CampaignNotificationSignatureDelegate.h"
#include "DelegateDelegate.h"
#include "SpaceRigNotification.h"
#include "NotificationSubSystem.generated.h"

class UCampaignNotification;
UCLASS(Blueprintable)
class ROGUECORE_API UNotificationSubSystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    TArray<FSpaceRigNotification> SpaceRigNotifications;

    UCampaignNotification* CampaignNotification;

    UNotificationSubSystem();

    UFUNCTION(BlueprintCallable)

    bool GetNextSpaceRigNotification(FSpaceRigNotification& NextNotification);

    void ClearCampaignNotifications();



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnNewSpaceRigNotificationEvent;
    
    FCampaignNotificationSignature OnCampaignNotification;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSpaceRigNotification> SpaceRigNotifications;
    UCampaignNotification* CampaignNotification;
    UNotificationSubSystem();
    UFUNCTION(BlueprintCallable)
    bool GetNextSpaceRigNotification(FSpaceRigNotification& NextNotification);
    void ClearCampaignNotifications();
    void AddSpaceRigNotification(FSpaceRigNotification NewNotification, const FString& ID, bool TriggerEvent);
};
