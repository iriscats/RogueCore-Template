#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "DeepPathFinderSize.h"
#include "Templates/SubclassOf.h"
#include "AreaSpawnerComponent.generated.h"

class AActor;
class APawn;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAreaSpawnerComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorToSpawn;
    
    DeepPathFinderSize PathfinderSize;
    float ChanceToSpawn;
    UAreaSpawnerComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SpawnInArea(const FVector& Origin, float Radius, float maxVerticalDistance, APawn* Instigator);
};
