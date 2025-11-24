#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameActivitySettings.generated.h"

class UGameActivityType;
UCLASS(Blueprintable)
class UGameActivitySettings : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UGameActivityType>> GameActivites;
    
    UGameActivitySettings();
};
