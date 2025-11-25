#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GenerationItem.h"
#include "RandomSubRoomItem.generated.h"

class URoomGeneratorGroup;
UCLASS(Blueprintable)
class ARandomSubRoomItem : public AGenerationItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URoomGeneratorGroup* RoomGroup;
    
    FGameplayTagQuery TagQuery;
    int32 Layer;
    ARandomSubRoomItem(const FObjectInitializer& ObjectInitializer);
};
