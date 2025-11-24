#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoomFeature.h"
#include "FloodFillProceduralPillar.generated.h"

class UPillarSettings;
UCLASS(Blueprintable, EditInlineNew)
class UFloodFillProceduralPillar : public URoomFeature {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> Points;

    UPillarSettings* PillarSettings;

public:
    UFloodFillProceduralPillar();
};
