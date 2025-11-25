#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SoftMinersManualDescription.h"
#include "MinersManualData.generated.h"

class UTexture2D;
UCLASS(Blueprintable)
class UMinersManualData : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftMinersManualDescription Description;
    
    UMinersManualData();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetText(FText& Headline, FText& richText);
    UTexture2D* GetFrontImage();
    UTexture2D* GetBackgroundImage();
};
