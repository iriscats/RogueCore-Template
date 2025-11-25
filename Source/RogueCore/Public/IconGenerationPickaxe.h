#pragma once
#include "CoreMinimal.h"
#include "IconGenerationBase.h"
#include "IconGenerationPickaxe.generated.h"

class UPickaxeIconSceneCaptureComponent;
UCLASS(Blueprintable)
class AIconGenerationPickaxe : public AIconGenerationBase {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPickaxeIconSceneCaptureComponent*> CaptureComponents;
    
    AIconGenerationPickaxe(const FObjectInitializer& ObjectInitializer);
};
