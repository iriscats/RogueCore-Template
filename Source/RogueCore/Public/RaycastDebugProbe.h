#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RaycastDebugProbe.generated.h"

class UTerrainType;
UCLASS(Blueprintable, NoExport)
class ARaycastDebugProbe : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainType* TerrainType;
    
    ARaycastDebugProbe(const FObjectInitializer& ObjectInitializer);
};
