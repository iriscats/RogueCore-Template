#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EVanitySlot.h"
#include "VanityTestCharacterItem.h"
#include "VanityTestCharacter.generated.h"

class USkeletalMesh;
UCLASS(Blueprintable)
class AVanityTestCharacter : public ACharacter {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ArmorThickness;
    
    float BeardThickness;
    bool ArmorCoversBeard;
    TMap<EVanitySlot, FVanityTestCharacterItem> VanityItems;
    USkeletalMesh* WeaponMesh;
    AVanityTestCharacter(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetupVanity();
};
