#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnemyFamily.generated.h"

class UTexture2D;
UCLASS(Blueprintable)
class UEnemyFamily : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    FText Name;
    UEnemyFamily();
};
