#pragma once
#include "CoreMinimal.h"
#include "GenerationItem.h"
#include "SubRoomItem.generated.h"

class URoomGenerator;
UCLASS(Blueprintable, NoExport)
class ASubRoomItem : public AGenerationItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    URoomGenerator* RoomGenerator;

    

    int32 Layer;

    ASubRoomItem(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URoomGenerator* RoomGenerator;
    
    int32 Layer;
    ASubRoomItem(const FObjectInitializer& ObjectInitializer);
};
