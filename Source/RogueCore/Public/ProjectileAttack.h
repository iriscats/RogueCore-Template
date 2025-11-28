#pragma once
#include "CoreMinimal.h"

#include "UObject/Object.h"
#include "ProjectileAttack.generated.h"

UCLASS(Abstract, Blueprintable, DefaultToInstanced, EditInlineNew)
class UProjectileAttack : public UObject {
    GENERATED_BODY()
    

public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval Delay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TriggerOnEvent;
    FFloatInterval HorizontalAngleOffset;
    FFloatInterval VerticalAngleOffset;
    FName OverrideSocketName;
    UProjectileAttack();
};
