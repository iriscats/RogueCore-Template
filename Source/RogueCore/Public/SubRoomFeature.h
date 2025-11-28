#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoomFeature.h"
#include "SubRoomFeature.generated.h"

class URoomGenerator;
UCLASS(Blueprintable, EditInlineNew)
class USubRoomFeature : public URoomFeature {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URoomGenerator* RoomGenerator;
    
    FVector Location;
    FRotator Rotation;
    float Scale;
    USubRoomFeature();
};
