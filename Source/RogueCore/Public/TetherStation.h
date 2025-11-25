#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "TetherStation.generated.h"

class AFacilityGeneratorLine;
class USceneComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ATetherStation : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneRoot;
    
    USkeletalMeshComponent* BaseMesh;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AFacilityGeneratorLine> FacilityGeneratorLineType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_AreGeneratorsReady, meta=(AllowPrivateAccess=true))
    bool AreGeneratorsReady;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=Onrep_FacilityActive, meta=(AllowPrivateAccess=true))
    bool FacilityActive;
    ATetherStation(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SpawnGeneratorLines(const FTransform& startL, const FTransform& startR, const TArray<FTransform>& endL, const TArray<FTransform>& endR, AFacilityGeneratorLine*& outLineL, AFacilityGeneratorLine*& outLineR);
    void SetGeneratorsReady(bool ready);
    UFUNCTION(BlueprintCallable)
    void Onrep_FacilityActive();
    UFUNCTION()
    void OnRep_AreGeneratorsReady();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGeneratorsReady();
    void OnActivated();
    void DisableShields();
    void ActivateFacility();
};
