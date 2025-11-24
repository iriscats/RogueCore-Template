#pragma once
#include "CoreMinimal.h"
#include "TagEffectDataBase.h"
#include "WeaponTagInitData.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FWeaponTagInitData : public FTagEffectDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> EquippedItems;
    
    ROGUECORE_API FWeaponTagInitData();
};
