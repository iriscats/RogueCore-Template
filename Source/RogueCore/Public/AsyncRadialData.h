#pragma once
#include "CoreMinimal.h"
#include "DamageBonuses.h"
#include "DamageInstance.h"
#include "DamageParams.h"
#include "AsyncRadialData.generated.h"

USTRUCT(BlueprintType)
struct FAsyncRadialData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDamageInstance instance;
    
    FDamageParams Params;
    FDamageBonuses Bonuses;
    ROGUECORE_API FAsyncRadialData();
};
