#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TerrainScannerMeshTrackingSubsystem.generated.h"

class UTerrainScannerStaticMesh;
UCLASS(Blueprintable)
class UTerrainScannerMeshTrackingSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTerrainScannerStaticMesh*> Instances;
    
    UTerrainScannerMeshTrackingSubsystem();
};
