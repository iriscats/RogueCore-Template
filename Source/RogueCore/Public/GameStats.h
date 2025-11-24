#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameStats.generated.h"

class UCappedResource;
class USeamlessTravelEventKey;
UCLASS(Blueprintable, NoExport)
class AGameStats : public AInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float TotalGoldMined;
    
    int32 TotalEnemiesKilled;
    TArray<USeamlessTravelEventKey*> EventKeys;
    AGameStats(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnPlayerMinedGold(UCappedResource* Resource, float amount);
};
