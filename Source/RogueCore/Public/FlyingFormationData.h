#pragma once
#include "CoreMinimal.h"
#include "FormationData.h"
#include "FlyingFormationData.generated.h"

UCLASS(Blueprintable)
class UFlyingFormationData : public UFormationData {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FormationSize;

    float FormationSpread;

    float RandomSpread;

public:
    UFlyingFormationData();
};
