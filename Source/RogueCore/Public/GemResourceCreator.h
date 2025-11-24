#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GemResourceCreator.generated.h"

class UGemResourceData;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UGemResourceCreator : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGemResourceData* ResourceData;
    
    bool CheckIfFreeSpaceAbove;
    int32 SearchSize;
    UGemResourceCreator();
};
