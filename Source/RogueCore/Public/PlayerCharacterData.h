#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "DialogVoiceSettings.h"
#include "ECharacterIconType.h"
#include "HeroInfo.h"
#include "PlayerCharacterData.generated.h"

class UPlayerCharacterID;
class UTexture2D;
UCLASS(Blueprintable)
class ROGUECORE_API UPlayerCharacterData : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayerCharacterID* characterID;
    
    FHeroInfo HeroInfo;
    FDialogVoiceSettings VoiceSettings;
    UPlayerCharacterData();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FDialogVoiceSettings GetVoiceSettings() const;
    FText GetSwitchToMessage() const;
    UTexture2D* GetSmallIconSimplified() const;
    UTexture2D* GetSmallIconDropShadow() const;
    UTexture2D* GetSmallIcon() const;
    FText GetShortDescription() const;
    FText GetName() const;
    FText GetLongDescription() const;
    UTexture2D* GetIconType(ECharacterIconType InType);
    UTexture2D* GetIcon() const;
    UTexture2D* GetFullSizeImage() const;
    FLinearColor GetColor() const;
};
