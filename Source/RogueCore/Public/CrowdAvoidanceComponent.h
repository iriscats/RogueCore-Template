#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "CrowdAvoidanceComponent.generated.h"

class ACrowdAvoidanceManager;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UCrowdAvoidanceComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvoidanceRadius;
    
    FVector AvoidanceDirection;
    int32 AvoidanceCount;
 
    ACrowdAvoidanceManager* CrowdAvoidanceManager;
    UCrowdAvoidanceComponent(const FObjectInitializer& ObjectInitializer);
};
