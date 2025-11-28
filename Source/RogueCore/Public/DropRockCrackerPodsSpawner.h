#pragma once
#include "CoreMinimal.h"
#include "DebrisLocationFinder.h"
#include "DropRockCrackerPodsSpawner.generated.h"

class AActor;
class APlagueMeteor;
UCLASS(Blueprintable)
class ADropRockCrackerPodsSpawner : public ADebrisLocationFinder {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlagueMeteor* meteor;
    
    TSoftClassPtr<APlagueMeteor> MeteorActorClass;
    TSoftClassPtr<AActor> RockCrackerIndicationClass;
    ADropRockCrackerPodsSpawner(const FObjectInitializer& ObjectInitializer);
};
