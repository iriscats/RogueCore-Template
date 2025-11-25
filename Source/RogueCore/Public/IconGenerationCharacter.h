#pragma once
#include "CoreMinimal.h"
#include "IconGenerationBase.h"
#include "IconGenerationCharacter.generated.h"

class UBeardColorVanityItem;
class UIconSceneCaptureComponent;
class UMaterialInterface;
class USkeletalMeshComponent;
UCLASS(Blueprintable)
class AIconGenerationCharacter : public AIconGenerationBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* OrigBaseMaterial;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* mesh;
    USkeletalMeshComponent* BodyMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBeardColorVanityItem* HairColor;
    UMaterialInterface* ArmorMaterial;
    UMaterialInterface* UndersuitMaterial;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UIconSceneCaptureComponent*> CaptureComponents;
    AIconGenerationCharacter(const FObjectInitializer& ObjectInitializer);
};
