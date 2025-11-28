#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BuildRestriction.generated.h"

UCLASS(Blueprintable)
class UBuildRestriction : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BuildType;
    
    int32 Platform;
    UBuildRestriction();
};
