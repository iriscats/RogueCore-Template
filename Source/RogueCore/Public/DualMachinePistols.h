#pragma once
#include "CoreMinimal.h"
#include "DualWieldWeapon.h"
#include "Templates/SubclassOf.h"
#include "DualMachinePistols.generated.h"

class UStatusEffect;
UCLASS(Blueprintable)
class ADualMachinePistols : public ADualWieldWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> EmptyClipStatusEffect;
    
    ADualMachinePistols(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_TriggerStatusEffect();
};
