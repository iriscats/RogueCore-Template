#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "BackendNotificationEvent.h"
#include "EHolidayType.h"
#include "FSDEventActivateChangedDelegate.h"
#include "JettyBootEventSettings.h"
#include "OnRequestSeasonEndTimeCompleteDelegate.h"
#include "FSDEventManager.generated.h"

class UFSDEvent;
UCLASS(Blueprintable)
class UFSDEventManager : public UGameInstanceSubsystem {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFSDEventsRefreshDelegate);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFSDEventsRefreshDelegate OnFSDEventsRefresh;
    FFSDEventActivateChanged OnEventActiveChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<FName> PendingActiveEvents;
    TSet<FName> ActiveEvents;
    int32 NumFailedRequests;
    bool BackendDataValid;
    FDateTime LastRequestTime;
    float NextCheckTime;
    FDateTime SeasonExpirationTime;
    bool SeasonExpirationTimeValid;
    bool BackendNotificationEventValid;
    UFSDEventManager();
    UFUNCTION(BlueprintCallable)
    void TryGetJettyBootSettings(bool& OutHasSettings, FJettyBootEventSettings& OutSettings);
    void RequestSeasonEndTime(FOnRequestSeasonEndTimeComplete OnComplete);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEventTypeActive(const EHolidayType FSDEvent) const;
    bool IsEventActive(const UFSDEvent* FSDEvent) const;
    bool GetSeasonExpiryDate(FDateTime& ExpiryDate);
    EHolidayType GetHolidayType() const;
    UFSDEvent* GetFirstActiveEventHandler() const;
    bool GetBackendNotificationEvent(FBackendNotificationEvent& Notification);
    TArray<UFSDEvent*> GetActiveEventHandlers() const;
    bool FSDEventsReady() const;
};
