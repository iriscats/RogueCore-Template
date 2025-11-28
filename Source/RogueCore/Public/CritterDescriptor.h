#pragma once
#include "CoreMinimal.h"
#include "BaseCritterDescriptor.h"
#include "IRandRange.h"
#include "CritterDescriptor.generated.h"

UCLASS(Blueprintable)
class UCritterDescriptor : public UBaseCritterDescriptor {
    GENERATED_BODY()
    

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIRandRange SpawnAmountPerRoom;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnChancePerRoom;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIRandRange SpawnAmountPerLevel;

    UCritterDescriptor();

};
