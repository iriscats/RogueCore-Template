#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MissionStatsCollector.generated.h"

class APlayerCharacter;
class UCappedResource;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMissionStatsCollector : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    
    UMissionStatsCollector(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnResourceIncremented(UCappedResource* Resource, float amount);
};
