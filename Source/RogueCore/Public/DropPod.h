#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MiningPodDialogs.h"
#include "TeamTransport.h"
#include "DropPod.generated.h"

class UAutoCarverComponent;
class UCurveFloat;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ADropPod : public ATeamTransport {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMiningPodDialogs Dialogs;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAutoCarverComponent* AutoCarverComp;
    UCurveFloat* CarverDropCurve;
    float CarverRotationSpeed;
    FVector CarverScale;
    ADropPod(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector GetDonkeyReturnPickupLocation();
};
