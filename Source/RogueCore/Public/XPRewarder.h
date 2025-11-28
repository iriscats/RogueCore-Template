#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "XPRewarder.generated.h"

class UBXEBlueprintControlledObjective;
UCLASS(Blueprintable)
class AXPRewarder : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBXEBlueprintControlledObjective* RewardObjective;
    

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
