#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ERoomMirroringSupport.h"
#include "RoomGeneratorBase.generated.h"

UCLASS(Abstract, Blueprintable)
class URoomGeneratorBase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Bounds;
    
    bool CanOnlyBeUsedOnce;
    ERoomMirroringSupport MirrorSupport;
    FGameplayTagContainer RoomTags;
    URoomGeneratorBase();
};
