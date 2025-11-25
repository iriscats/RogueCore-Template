#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FSDPhysicsActor.h"
#include "ResourceChunk.generated.h"

class APlayerCharacter;
class AResourceChunk;
class UBXEBlueprintControlledObjective;
class UObject;
class UResourceData;
class USimpleObjectInfoComponent;
class USoundCue;
UCLASS(Blueprintable)
class ROGUECORE_API AResourceChunk : public AFSDPhysicsActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CollectDuration;
    
    bool CanBeCollectedNormally;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool CanBeCollected;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimpleObjectInfoComponent* InfoComponent;
    float ResourceAmount;
    USoundCue* PickupSound;
    UResourceData* ResourceData;
    TArray<APlayerCharacter*> OverlappingPlayers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CollectedBy, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> CollectedBy;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBXEBlueprintControlledObjective* SpawnedByObjective;
    AResourceChunk(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AResourceChunk* SpawnChunk(UObject* WorldContextObject, UResourceData* Data, float Size, FVector position);
    UFUNCTION(BlueprintCallable)
    void SetCollectOpen();
    UFUNCTION()
    void OnRep_CollectedBy();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UResourceData* GetResourceData() const;
    float GetResourceAmount() const;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CalcMovement(float InProgress, const FVector& InVector, FVector& OutVelocity, FVector& OutAngularVelocity);
};
