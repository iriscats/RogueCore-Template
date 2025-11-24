#pragma once
#include "CoreMinimal.h"
#include "IconGenerationBase.h"
#include "IconGenerationPickaxe.generated.h"

class UPickaxeIconSceneCaptureComponent;
UCLASS(Blueprintable, NoExport)
class AIconGenerationPickaxe : public AIconGenerationBase {
    GENERATED_BODY()

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPickaxeIconSceneCaptureComponent*> CaptureComponents;
    
    AIconGenerationPickaxe(const FObjectInitializer& ObjectInitializer);
};
