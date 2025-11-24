#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CritterManager.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCritterManager : public UActorComponent {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableCritters;

    float ActivationRange;

public:
    UCritterManager(const FObjectInitializer& ObjectInitializer);
};
