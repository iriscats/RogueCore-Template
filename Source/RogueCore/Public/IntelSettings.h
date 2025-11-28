#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IntelSettings.generated.h"

class UIntelObjective;
UCLASS(Blueprintable)
class UIntelSettings : public UDataAsset {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UIntelObjective*> IntelProgression;
    
    UIntelSettings();
};
