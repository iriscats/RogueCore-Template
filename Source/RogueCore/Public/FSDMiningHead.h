#pragma once
#include "CoreMinimal.h"
#include "DroppableOutpost.h"
#include "FSDMiningHead.generated.h"

class UResourceBank;
UCLASS(Blueprintable)
class ROGUECORE_API AFSDMiningHead : public ADroppableOutpost {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UResourceBank* ResourceBank;
    
    AFSDMiningHead(const FObjectInitializer& ObjectInitializer);
};
