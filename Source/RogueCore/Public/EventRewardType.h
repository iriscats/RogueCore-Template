#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "EventRewardType.generated.h"

class UTexture2D;
UCLASS(Blueprintable)
class UEventRewardType : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    TSoftObjectPtr<UTexture2D> IconFront;
    TSoftObjectPtr<UTexture2D> IconBack;
    FLinearColor IconFrontTint;
    FLinearColor IconBackTint;
    FLinearColor BackgroundTint;
    UEventRewardType();
};
