#pragma once
#include "CoreMinimal.h"
#include "FSDAIController.h"
#include "FSDFlyingBugController.generated.h"

class UBehaviorTree;
UCLASS(Blueprintable)
class AFSDFlyingBugController : public AFSDAIController {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* BehaviourTree;

 
    float UpdateLosInterval;
    bool SetTargetOnAlert;
    bool SyncTargetWithBB;
    AFSDFlyingBugController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnFlyingBugAlerted();
};
