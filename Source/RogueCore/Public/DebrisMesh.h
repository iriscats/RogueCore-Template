#pragma once
#include "CoreMinimal.h"
#include "DebrisBase.h"
#include "DebrisStaticMesh.h"
#include "DebrisMesh.generated.h"

class UMaterialInterface;
UCLASS(Blueprintable, EditInlineNew)
class UDebrisMesh : public UDebrisBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDebrisStaticMesh> Meshes;
    
    UMaterialInterface* CommonMaterial;
    FText InGameName;
    FName GemTrackerName;
    FText InGameDescription;
    float StartCullDistance;
    float EndCullDistance;
    UDebrisMesh();
};
