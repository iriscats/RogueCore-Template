#pragma once
#include "CoreMinimal.h"
#include "TagEffectDataBase.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FTagEffectDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Target;
    
    AActor* Weapon;
    AActor* Character;
    ROGUECORE_API FTagEffectDataBase();
};
