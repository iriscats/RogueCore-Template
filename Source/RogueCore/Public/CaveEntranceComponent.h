#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "ECaveEntrancePriority.h"
#include "ECaveEntranceType.h"
#include "CaveEntranceComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCaveEntranceComponent : public UPrimitiveComponent {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECaveEntranceType Direction;

    ECaveEntrancePriority Priority;

public:
    UCaveEntranceComponent(const FObjectInitializer& ObjectInitializer);
};
