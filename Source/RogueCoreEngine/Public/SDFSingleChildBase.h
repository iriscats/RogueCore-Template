#pragma once
#include "CoreMinimal.h"
#include "SDFBase.h"
#include "SDFSingleChildBase.generated.h"

UCLASS(Blueprintable)
class ROGUECOREENGINE_API USDFSingleChildBase : public USDFBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USDFBase* Child;
    
    USDFSingleChildBase();

};

