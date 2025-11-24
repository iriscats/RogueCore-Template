#pragma once
#include "CoreMinimal.h"
#include "CSGOptions.h"
#include "Templates/SubclassOf.h"
#include "CSGChildInstanceProperties.generated.h"

class ACSGBuilder;

USTRUCT(BlueprintType)
struct FCSGChildInstanceProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACSGBuilder> mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCSGOptions Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    ROGUECOREENGINE_API FCSGChildInstanceProperties();
};

