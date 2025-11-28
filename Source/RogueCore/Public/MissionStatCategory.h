#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MissionStatCategory.generated.h"

class UTexture2D;
UCLASS(Blueprintable)
class UMissionStatCategory : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UTexture2D* Icon;
    UMissionStatCategory();
};
