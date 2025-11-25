#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResourcesSave.generated.h"

USTRUCT(BlueprintType)
struct FResourcesSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGuid, float> OwnedResources;
    ROGUECORE_API FResourcesSave();
 
};
