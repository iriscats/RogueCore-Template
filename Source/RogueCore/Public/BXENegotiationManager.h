#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BXENegotiationData.h"
#include "DelegateDelegate.h"
#include "OnReportNegotiationResultDelegate.h"
#include "BXENegotiationManager.generated.h"

class UBXEUnlockBase;
class URunManager;
UCLASS(Blueprintable)
class ROGUECORE_API UBXENegotiationManager : public UObject {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnNegotiationDone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReportNegotiationResult OnReportNegotiationResult;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URunManager* BXEManager;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBXENegotiationData NegotiationData;
    TArray<UBXEUnlockBase*> DroneRewardHistory;
    UBXENegotiationManager();
};
