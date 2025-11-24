#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ECaveEntrancePriority.h"
#include "ECaveEntranceType.h"
#include "RoomFeature.h"
#include "EntranceFeature.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEntranceFeature : public URoomFeature {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;

    FRotator Direction;

    ECaveEntranceType EntranceType;

    ECaveEntrancePriority Priority;

public:
    UEntranceFeature();
};
