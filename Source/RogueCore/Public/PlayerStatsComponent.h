#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "EndMissionResult.h"
#include "Templates/SubclassOf.h"
#include "PlayerStatsComponent.generated.h"

class APlayerCharacter;
class UCappedResource;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerStatsComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnKillAdded;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    int32 TotalKills;
    int32 TotalRevived;
    int32 TotalDeaths;
    int32 TotalSupplypodsRequested;
    float TotalGoldMined;
    float TotalMOMsMined;
    float TotalMineralsMined;
    float TotalXPGained;
    float TotalHealthRestored;
    bool EscapedInPod;
    TSubclassOf<APlayerCharacter> LastPlayedClass;
    FEndMissionResult EndMissionResult;
    UClass* CauseOfDeathClass;
    UPlayerStatsComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SendMissionAnalytics(bool trackMorkite);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void SendEndMissionResult(const FEndMissionResult& Result);
    void OnResourceMined(UCappedResource* Resource, float amount);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEndMissionResultReady() const;
    bool GetSurvivedInPod() const;
    FEndMissionResult GetEndMissionResult() const;
};
