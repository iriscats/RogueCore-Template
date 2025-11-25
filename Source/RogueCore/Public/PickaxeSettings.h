#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DefaultPickaxeParts.h"
#include "PickaxeSettings.generated.h"

class UAnimMontage;
class UPickaxePart;
UCLASS(Blueprintable)
class UPickaxeSettings : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* Salute_FP;
    
    UAnimMontage* Salute_TP;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPickaxePart*> Parts;
    FDefaultPickaxeParts DefaultPickaxeParts;
    UPickaxeSettings();
};
