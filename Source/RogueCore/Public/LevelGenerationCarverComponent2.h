#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "CSGOptions.h"
#include "Templates/SubclassOf.h"
#include "LevelGenerationCarverComponent2.generated.h"

class ACSGBuilder;
class UCSGPreviewComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULevelGenerationCarverComponent2 : public UPrimitiveComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACSGBuilder> Carver;
    
    bool CarvingDisabled;
    int32 PreviewSeed;
    FCSGOptions CarverSettings;
protected:
    bool SelfActivate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCSGPreviewComponent* PreviewComponent;
    ULevelGenerationCarverComponent2(const FObjectInitializer& ObjectInitializer);
};
