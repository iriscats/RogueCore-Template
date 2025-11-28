#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "CSGOptions.h"
#include "CSGBuilderBase.generated.h"

class UBakeConfig;
class UCSGPreviewComponent;
class UTerrainMaterialCore;

UCLASS(Blueprintable)
class ROGUECOREENGINE_API ACSGBuilderBase : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox BoundingBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PreviewSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCSGOptions PreviewSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterialCore* EmptyMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterialCore* ErrorMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterialCore* SolidMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterialCore* BurnedMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCSGPreviewComponent* PreviewComponent;
    
    ACSGBuilderBase(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PreGenerate(UBakeConfig* builder);
    
};

