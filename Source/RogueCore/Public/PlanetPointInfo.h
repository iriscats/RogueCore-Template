#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EPointVisibility.h"
#include "PlanetPointInfo.generated.h"

class USceneComponent;
USTRUCT(BlueprintType)
struct FPlanetPointInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Point = nullptr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ScreenLocation = FVector2D::ZeroVector;
    EPointVisibility Visibility;

};
