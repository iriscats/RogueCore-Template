#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DamageNumberHitSetting.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FDamageNumberHitSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor HitColor;
    
    UTexture2D* HitTypeIcon;
    bool IsIconTintAlwaysSameAsHitColor;
    FLinearColor HitTypeIconTint;
    ROGUECORE_API FDamageNumberHitSetting();
};
