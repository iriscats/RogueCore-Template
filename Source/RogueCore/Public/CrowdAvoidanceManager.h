#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrowdAvoidanceManager.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API ACrowdAvoidanceManager : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> AllCrowdActors;
    
    ACrowdAvoidanceManager(const FObjectInitializer& ObjectInitializer);
};
