#pragma once
#include "CoreMinimal.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "WidgetComponentCustomMaterial.generated.h"

class UMaterialInterface;
UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWidgetComponentCustomMaterial : public UWidgetComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* CustomMaterial;

    UWidgetComponentCustomMaterial(const FObjectInitializer& ObjectInitializer);
};
