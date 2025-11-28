#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "BasicColorAsset.generated.h"

UCLASS(Blueprintable)
class BASICUI_API UBasicColorAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
public:
    UBasicColorAsset();

};

