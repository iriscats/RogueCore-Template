#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "EnemySpawnEffectsByKeyAnimNotify.generated.h"

class UEnemySpawnEffectsKey;
UCLASS(Blueprintable, CollapseCategories, MinimalAPI)
class UEnemySpawnEffectsByKeyAnimNotify : public UAnimNotify {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    UEnemySpawnEffectsKey* EffectKey;

    

    uint8 Attached: 1;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemySpawnEffectsKey* EffectKey;
    
    uint8 Attached: 1;
    FName SocketName;
    UEnemySpawnEffectsByKeyAnimNotify();
};
