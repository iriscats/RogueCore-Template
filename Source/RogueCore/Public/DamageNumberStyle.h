#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "Curves/CurveFloat.h"
#include "Runtime/SlateCore/Public/Fonts/SlateFontInfo.h"
#include "CritDisplay.h"
#include "DamageNumberHitSetting.h"
#include "EDamageNumberHitType.h"
#include "Templates/SubclassOf.h"
#include "DamageNumberStyle.generated.h"

class UDamageNumberWidget;
UCLASS(Blueprintable)
class UDamageNumberStyle : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageNumberWidget> DamageNumberWidgetClass;
    
    FRuntimeFloatCurve ScaleToDamage;
    TMap<EDamageNumberHitType, FDamageNumberHitSetting> HitSetting;
    FLinearColor NormalHitColor;
    TArray<FCritDisplay> CriticalEffects;
    FCritDisplay FallbackCritDiplay;
    FSlateFontInfo RegularFont;
    float WeakPointSizeMultiplier;
    float RandomOffset;
    float Lifetime;
    float LifetimeVariance;
    int32 DecimalPrecision;
    UDamageNumberStyle();
};
