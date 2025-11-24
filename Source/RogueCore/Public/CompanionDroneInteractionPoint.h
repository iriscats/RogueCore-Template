#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CompanionDroneInteractionPoint.generated.h"

USTRUCT(BlueprintType)
struct FCompanionDroneInteractionPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ConnectorTransform;
    
    TArray<FVector> Locations;
    ROGUECORE_API FCompanionDroneInteractionPoint();
};
