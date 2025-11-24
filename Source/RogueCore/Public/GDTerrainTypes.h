#pragma once
#include "CoreMinimal.h"
#include "GDTerrainTypes.generated.h"

class UTerrainType;
USTRUCT(BlueprintType)
struct FGDTerrainTypes {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainType* Rock;
    
    UTerrainType* Dirt;
    ROGUECORE_API FGDTerrainTypes();
};
