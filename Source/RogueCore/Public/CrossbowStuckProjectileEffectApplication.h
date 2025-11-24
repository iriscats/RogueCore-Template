#pragma once
#include "CoreMinimal.h"
#include "CrossbowStuckProjectileEffect.h"
#include "CrossbowStuckProjectileEffectApplication.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCrossbowStuckProjectileEffectApplication : public UCrossbowStuckProjectileEffect {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SearchSphereSize;

    float SearchTime;

    bool CurrentlyActive;

public:
    UCrossbowStuckProjectileEffectApplication(const FObjectInitializer& ObjectInitializer);
};
