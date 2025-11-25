#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInstance.h"
#include "EVanitySlot.h"
#include "VanityAnimEffect.h"
#include "VanityAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UVanityAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVanitySlot VanitySlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ArmorCoversBeard;
    FVector ArmorChestThickness;
    FRotator ArmorChestRotation;
    FVector ExternalForce;
    float ExternalForceMultiplier;
    float MaxForce;
    TArray<FVanityAnimEffect> VanityAnimEffects;
    UVanityAnimInstance();
    UFUNCTION(BlueprintCallable)
    void UpdateMeshes();
};
