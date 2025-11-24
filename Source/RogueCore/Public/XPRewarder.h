#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "XPRewarder.generated.h"

class UBXEBlueprintControlledObjective;
UCLASS(Blueprintable, NoExport)
class AXPRewarder : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBXEBlueprintControlledObjective* RewardObjective;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float XRange;
    float YRange;
    float SpawnDelay;
    int32 ChunksToSpawn;
    int32 XPToAward;
    bool AutoActivate;
    AXPRewarder(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Activate(int32 XP);
};
