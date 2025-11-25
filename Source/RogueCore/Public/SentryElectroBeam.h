#pragma once
#include "CoreMinimal.h"
#include "ElectroBeam.h"
#include "SentryElectroBeam.generated.h"

class ARedeployableSentryGun;
UCLASS(Blueprintable, NoExport)
class ASentryElectroBeam : public AElectroBeam {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ARedeployableSentryGun*> Sentries;
    
    ASentryElectroBeam(const FObjectInitializer& ObjectInitializer);
};
