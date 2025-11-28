#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "StageNameBank.generated.h"

UCLASS(Blueprintable)
class UStageNameBank : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FText> FirstNames;
    
    TArray<FText> LastNames;
    UStageNameBank();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FText> GetRandomGeneratedNames(UPARAM(Ref) FRandomStream& Random, int32 count) const;
};
