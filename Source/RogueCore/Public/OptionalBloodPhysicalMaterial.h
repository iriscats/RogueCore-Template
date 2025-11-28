#pragma once
#include "CoreMinimal.h"
#include "FSDPhysicalMaterial.h"
#include "OptionalBloodPhysicalMaterial.generated.h"

class UNiagaraSystem;
UCLASS(Blueprintable, CollapseCategories)
class UOptionalBloodPhysicalMaterial : public UFSDPhysicalMaterial {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* BloodlessImpactParticles;
    
    UOptionalBloodPhysicalMaterial();
};
