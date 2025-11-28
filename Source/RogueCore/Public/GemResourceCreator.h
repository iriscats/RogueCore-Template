#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GemResourceCreator.generated.h"

class UGemResourceData;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UGemResourceCreator : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGemResourceData* ResourceData;
    
    bool CheckIfFreeSpaceAbove;
    int32 SearchSize;
    UGemResourceCreator();
};
