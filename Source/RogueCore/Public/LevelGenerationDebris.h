#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelGenerationDebris.generated.h"

class UDebrisBase;
class UObject;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULevelGenerationDebris : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDebrisBase* Debris;
    
protected:
    UObject* Influencer;
    float Range;
    bool SelfActivate;
    ULevelGenerationDebris(const FObjectInitializer& ObjectInitializer);
};
