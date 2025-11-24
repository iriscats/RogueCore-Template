#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ScrollBoxSettings.h"
#include "ScrollBoxAsset.generated.h"

UCLASS(Blueprintable)
class BASICUI_API UScrollBoxAsset : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScrollBoxSettings Settings;
    
public:
    UScrollBoxAsset();

};

