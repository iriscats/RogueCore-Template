#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "PlayerDamageTakenMutator.generated.h"

class UDamageClass;
UCLASS(Blueprintable, EditInlineNew)
class UPlayerDamageTakenMutator : public UMutator {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageMultiplier;
    
    TSet<UDamageClass*> SkipDamageClasses;
    UPlayerDamageTakenMutator();
};
