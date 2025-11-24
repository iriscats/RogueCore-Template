#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DamageClass.generated.h"

class UDamageImpulse;
class UDialogDataAsset;
class UElementType;
class UPawnStat;
class UTexture2D;
UCLASS(Blueprintable)
class UDamageClass : public UPrimaryDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPawnStat*> ScalingStats;
    
    UPawnStat* ResistanceStat;
    UTexture2D* IndicatorImage;
    UDialogDataAsset* DamageShout;
    UDamageImpulse* DefaultDamageImpulse;
    UElementType* ElementType;
    float RagdollScale;
    bool BypassesShield;
    bool IgnoreDifficultyScaling;
    bool AffectedByFriendlyFire;
    bool IgnoresWeakpointBonus;
    bool IgnoresArmorModifiers;
    bool AffectedByCriticalHits;
    UDamageClass();
};
