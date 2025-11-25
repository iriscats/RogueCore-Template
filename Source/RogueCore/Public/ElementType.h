#pragma once
#include "CoreMinimal.h"
#include "ConditionalElementEvent.h"
#include "EElementSourceIntensity.h"
#include "SavablePrimaryDataAsset.h"
#include "ElementType.generated.h"

class UElementEffects;
class UElementType;
class UElementTypeSettings;
class UPawnStat;
UCLASS(Blueprintable)
class UElementType : public USavablePrimaryDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ElementName;

    UElementType* TransferElement;
    int32 StackLimit;
    float StackResistanceMultiplier;
    bool HasReturnToNeutralIntensity;
    EElementSourceIntensity ReturnToNeutralIntensity;
    float ValueChangePerDamagePoint;
    float OverchargeBuffer;
    UPawnStat* PawnStatResistance;
    UElementEffects* ElementEffects;
    TArray<FConditionalElementEvent> Events;

 
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float Intensities[3];
    float IntensityStartDelay;
    UElementTypeSettings* ElementSettings;

public:
    UElementType();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UElementTypeSettings* GetElementSettings() const;
};
