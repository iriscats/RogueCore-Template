#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "UnlockVisualSettings.generated.h"

class USoundCue;
class UTexture2D;
UCLASS(Blueprintable)
class UUnlockVisualSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor RarityColor;
    
    FLinearColor RarityBackgroundColor;
    FLinearColor RarityTextColor;
    USoundCue* SelectedSound_Generic;
    USoundCue* SelectedSound_Weapons;
 
    TSoftObjectPtr<UTexture2D> FrameSoftPtr;
    UUnlockVisualSettings();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetFrame() const;
};
