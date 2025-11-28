#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EPawnStatType.h"
#include "PawnStat.generated.h"

UCLASS(Blueprintable)
class UPawnStat : public UDataAsset {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DisplayText;
    
    float StartingValue;
    EPawnStatType PawnStatType;
    EPawnStatType ValueModificationType;
    UPawnStat();
};
