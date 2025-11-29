#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EResourceFilterType.h"
#include "ResourceBankFilter.generated.h"

class UResourceData;
UCLASS(Blueprintable)
class UResourceBankFilter : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EResourceFilterType FilterType;
    
    TArray<UResourceData*> Resources;
    UResourceBankFilter();
};
