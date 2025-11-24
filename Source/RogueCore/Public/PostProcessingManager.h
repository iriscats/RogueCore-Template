#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PostProcessingBlendable.h"
#include "PostProcessingManager.generated.h"

class AFSDPostProcessingActor;
class UMaterialInstanceDynamic;
UCLASS(Blueprintable, NoExport)
class APostProcessingManager : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AFSDPostProcessingActor>> RegisteredActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPostProcessingBlendable> CurrentBlendables;
    TArray<UMaterialInstanceDynamic*> Materials;
    APostProcessingManager(const FObjectInitializer& ObjectInitializer);
};
