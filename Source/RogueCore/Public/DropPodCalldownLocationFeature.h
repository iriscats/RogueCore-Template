#pragma once
#include "CoreMinimal.h"

#include "RoomFeature.h"
#include "Templates/SubclassOf.h"
#include "DropPodCalldownLocationFeature.generated.h"

class AActor;
UCLASS(Blueprintable, EditInlineNew)
class UDropPodCalldownLocationFeature : public URoomFeature {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    TSubclassOf<AActor> CalldownClass;
    UDropPodCalldownLocationFeature();
};
