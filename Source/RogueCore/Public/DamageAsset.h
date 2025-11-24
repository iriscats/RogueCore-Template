#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DamageInstance.h"
#include "DamageAsset.generated.h"

UCLASS(Blueprintable)
class UDamageAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDamageInstance> damageInstances;
    
    float CriticalChanceBonus;
    UDamageAsset();
};
