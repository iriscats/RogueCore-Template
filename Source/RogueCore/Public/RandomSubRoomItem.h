#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GenerationItem.h"
#include "RandomSubRoomItem.generated.h"

class URoomGeneratorGroup;
UCLASS(Blueprintable, NoExport)
class ARandomSubRoomItem : public AGenerationItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URoomGeneratorGroup* RoomGroup;
    
    FGameplayTagQuery TagQuery;
    int32 Layer;
    ARandomSubRoomItem(const FObjectInitializer& ObjectInitializer);
};
