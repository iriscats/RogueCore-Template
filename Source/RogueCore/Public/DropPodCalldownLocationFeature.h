#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoomFeature.h"
#include "Templates/SubclassOf.h"
#include "DropPodCalldownLocationFeature.generated.h"

class AActor;
UCLASS(Blueprintable, EditInlineNew)
class UDropPodCalldownLocationFeature : public URoomFeature {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    TSubclassOf<AActor> CalldownClass;
    UDropPodCalldownLocationFeature();
};
