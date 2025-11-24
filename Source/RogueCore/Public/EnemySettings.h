#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RandRange.h"
#include "Templates/SubclassOf.h"
#include "EnemySettings.generated.h"

class UDamageComponent;
UCLASS(Blueprintable)
class UEnemySettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange EnemyWaveRange;
    
    TArray<TSubclassOf<UDamageComponent>> ExplodingEnemiesDamageComponents;
    UEnemySettings();
};
