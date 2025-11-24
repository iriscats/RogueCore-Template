#pragma once
#include "CoreMinimal.h"
#include "EPlatformComponentCriteria.h"
#include "Templates/SubclassOf.h"
#include "PlatformComponent.generated.h"

class UActorComponent;
USTRUCT(BlueprintType)
struct FPlatformComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UActorComponent> ComponentClass;
    
    EPlatformComponentCriteria Criteria;
    ROGUECORE_API FPlatformComponent();
};
