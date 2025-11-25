#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorTrackingCheatInterface.h"
#include "EInputKeys.h"
#include "TreasureWeight.h"
#include "TreasureContainer.generated.h"

class APlayerCharacter;
class UItemAquisitionSource;
class UOncePerPlayerInstantUsableComponent;
class USceneComponent;
class UTreasureRewarder;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ATreasureContainer : public AActor, public IActorTrackingCheatInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UOncePerPlayerInstantUsableComponent* CollectUsable;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemAquisitionSource* AquisitionSource;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Collectors, meta=(AllowPrivateAccess=true))
    TArray<APlayerCharacter*> Collectors;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_LastJoiner, meta=(AllowPrivateAccess=true))
    APlayerCharacter* LastJoiner;
    TArray<FTreasureWeight> PossibleRewarders;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTreasureRewarder* TreasureRewarder;
    bool ShouldActivateCollectUsable;
    bool PreventLatejoiners;
    ATreasureContainer(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void TestAwardTreasure();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetPreventFurtherLatejoiners(bool prevent);
    void SetCanCollectTreasure(bool canCollect);
    UFUNCTION()
    void OnRep_LastJoiner();
    UFUNCTION()
    void OnRep_Collectors();
    void OnPlayerLatejoined(APlayerCharacter* joiner);
    void OnPlayerCollectedTreasure(APlayerCharacter* collector, EInputKeys Key);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLocalPlayerCollectedTreasure(APlayerCharacter* Player);
    void OnDisableChestLocally();
    void OnContainerActivated();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool GetPreventFurtherLatejoiners() const;
    // Fix for true pure virtual functions not being implemented
};
