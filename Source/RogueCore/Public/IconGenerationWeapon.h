#pragma once
#include "CoreMinimal.h"
#include "IconGenerationBase.h"
#include "IconGenerationWeapon.generated.h"

class UWeaponIconSceneCaptureComponent;
UCLASS(Blueprintable, NoExport)
class AIconGenerationWeapon : public AIconGenerationBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))

    TArray<UWeaponIconSceneCaptureComponent*> CaptureComponents;

    

    AIconGenerationWeapon(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UWeaponIconSceneCaptureComponent*> CaptureComponents;
    
    AIconGenerationWeapon(const FObjectInitializer& ObjectInitializer);
};
