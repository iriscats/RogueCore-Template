#pragma once
#include "CoreMinimal.h"

#include "DamageNumberHitSetting.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FDamageNumberHitSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor HitColor = FLinearColor::White;
    
    UTexture2D* HitTypeIcon;
    bool IsIconTintAlwaysSameAsHitColor;
    FLinearColor HitTypeIconTint;

};
