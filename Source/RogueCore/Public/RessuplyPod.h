#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "ERessuplyPodState.h"
#include "Templates/SubclassOf.h"
#include "RessuplyPod.generated.h"

class ARessuplyPod;
class UCurveFloat;
class UDamageComponent;
class UDialogDataAsset;
class UObject;
UCLASS(Blueprintable)
class ARessuplyPod : public AActor {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRessuplyPodStateDelegate, ARessuplyPod*, InPod, ERessuplyPodState, InState);

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRessuplyPodStateDelegate OnStateChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* Damage;
    float KillRadius;
    float DropHeight;
    float DropDelay;
    float MissionShoutDelay;
    UDialogDataAsset* ShoutDialogOrderAccepted;
    UDialogDataAsset* DialogOrderAccepted;
    UDialogDataAsset* DialogPodArrived;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* CurrentMissionShout;
    FVector StartLocation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TargetLocation, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    ERessuplyPodState State;
    float TargetDropTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float ServerDropProgress;
    UCurveFloat* DropCurve;
    AActor* PlayerSpawnPoint;
    float CloseToImpactDistance;
    ARessuplyPod(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetIdling();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTunnelBLocked();
    UFUNCTION(BlueprintCallable)
    void OnRep_TargetLocation();
    UFUNCTION()
    void OnRep_State(ERessuplyPodState oldState);
    void OnDropStarted();
    void OnDroppodImpact();
    void OnDroppodCloseToImpact();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AActor* DropToTarget(UObject* WorldContextObject, TSubclassOf<ARessuplyPod> podClass, const FVector& Location, AActor* Requester);
    // Gameplay tag functions
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const { return GameplayTags.HasTag(TagToCheck); }
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const { return GameplayTags.HasAny(TagContainer); }
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const { return GameplayTags.HasAll(TagContainer); }
    FGameplayTagContainer BP_GetOwnedGameplayTags() const { return GameplayTags; }
};
