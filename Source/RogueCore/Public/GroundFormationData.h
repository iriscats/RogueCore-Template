#pragma once
#include "CoreMinimal.h"
#include "FormationData.h"
#include "GroundFormationData.generated.h"

UCLASS(Blueprintable)
class UGroundFormationData : public UFormationData {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FormationSize;
    
    float FormationSpread;
    float RandomSpread;
    UGroundFormationData();
};
