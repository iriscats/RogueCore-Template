#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DamageNumberSettings.generated.h"

class UDamageNumberStyle;
UCLASS(Blueprintable)
class UDamageNumberSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageNumberStyle* DamageNumberStyle;
    
    int32 MaxDamageNumberCount;
    bool UndoDifficultyScaling;
    bool EnableCombineNumbers;
    UDamageNumberSettings();
};
