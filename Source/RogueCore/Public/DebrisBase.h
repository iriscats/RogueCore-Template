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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve InfluencerDensityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve InfluencerSizeCurve;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CaveInfluenceCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CaveInflunceSizeCurve;
    
public:
    UDebrisBase();

};
