#pragma once
#include "CoreMinimal.h"
#include "DroppableOutpost.h"
#include "FSDMiningHead.generated.h"

class UResourceBank;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AFSDMiningHead : public ADroppableOutpost {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UResourceBank* ResourceBank;
    
    AFSDMiningHead(const FObjectInitializer& ObjectInitializer);
};
