#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoomFeature.h"
#include "ResourceFeature.generated.h"

class UResourceData;
UCLASS(Blueprintable, EditInlineNew)
class UResourceFeature : public URoomFeature {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    UResourceData* Resource;
    float BaseAmount;
    UResourceFeature();
};
