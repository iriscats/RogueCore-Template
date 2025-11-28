#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "ElementTypeSettings.generated.h"

class UTexture2D;
UCLASS(Blueprintable)
class UElementTypeSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    FColor FillColor;
    FColor IconColorBG;
    bool ShowOnEnemyHealthBar;
    UElementTypeSettings();
};
