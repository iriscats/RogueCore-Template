#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "CSGTriangleMapper.h"
#include "DebrisBase.generated.h"

class UCurveFloat;
class UObject;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class ROGUECORE_API UDebrisBase : public UCSGTriangleMapper {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* CaveInfluencer;

    FRuntimeFloatCurve InfluencerDensityCurve;
    FRuntimeFloatCurve InfluencerSizeCurve;

    UDebrisBase();

 
    UCurveFloat* CaveInfluenceCurve;
    UCurveFloat* CaveInflunceSizeCurve;
};
