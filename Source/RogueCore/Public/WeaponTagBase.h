#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponTagBase.generated.h"

class UTexture2D;
UCLASS(Abstract, Blueprintable)
class UWeaponTagBase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    FText TagName;
    UWeaponTagBase();
};
