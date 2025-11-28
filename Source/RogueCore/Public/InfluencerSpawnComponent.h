#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "InfluencerSpawnComponent.generated.h"

class UCaveInfluencer;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInfluencerSpawnComponent : public USceneComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCaveInfluencer* Influencer;
    
    float Range;
    UInfluencerSpawnComponent(const FObjectInitializer& ObjectInitializer);
};
