#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "RoomFeature.h"
#include "RandomSubRoomFeature.generated.h"

class URoomGeneratorGroup;
UCLASS(Blueprintable, EditInlineNew)
class URandomSubRoomFeature : public URoomFeature {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URoomGeneratorGroup* RoomGroup;
    
    FGameplayTagQuery TagQuery;
    int32 Layer;
    FVector Location;
    FRotator Rotation;
    float Scale;
    URandomSubRoomFeature();
};
