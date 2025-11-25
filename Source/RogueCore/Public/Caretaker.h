#pragma once
#include "CoreMinimal.h"
#include "ECaretakerSpawnType.h"
#include "FSDPawn.h"
#include "Caretaker.generated.h"

class UAnimSequenceBase;
class UCaretakerActionComponent;
class UEnemyHealthComponent;
class UHealthDamageTracker;
class UPassthroughSubHealthComponent;
class UPawnStatsComponent;
class USceneComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable)
class ROGUECORE_API ACaretaker : public AFSDPawn {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USkeletalMeshComponent* Body;
    TArray<USkeletalMeshComponent*> Eyes;
    TArray<UPassthroughSubHealthComponent*> subHealth;
    UHealthDamageTracker* DamageTracker;
    UEnemyHealthComponent* Health;
    UPawnStatsComponent* PawnStats;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UCaretakerActionComponent*> Actions;
    UCaretakerActionComponent* CurrentAction;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimSequenceBase*> HitReactions;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CurrentStage, meta=(AllowPrivateAccess=true))
    int32 CurrentStage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 TargetRotationRate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<float> RotationRates;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Server_Rotation, meta=(AllowPrivateAccess=true))
    float Server_Rotation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsInStageCooldown;
    bool IsWeakpointAVisible;
    bool IsWeakpointBVisible;
    bool IsWeakpointCVisible;
    bool IsWeakpointDVisible;
    ECaretakerSpawnType ActiveSpawnType;
    int32 AoEStage;
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_OpenEye, meta=(AllowPrivateAccess=true))
    int8 OpenEye;
    ACaretaker(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void WakeUp();
    void SetTargetRotationRate(int32 rateIndex);
    void OpenRandomEye(bool forbidLastEye);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartHideFromDamage();
    UFUNCTION(BlueprintCallable)
    void OnRep_Server_Rotation();
    UFUNCTION()
    void OnRep_OpenEye();
    UFUNCTION()
    void OnRep_CurrentStage();
    void OnNewStage(int32 StageIndex);
    void OnEyeOpened(USkeletalMeshComponent* eye);
    void OnEyeClosed(USkeletalMeshComponent* eye);
    void OnDamageTaken(float amount);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAwake() const;
    bool IsAnyEyeOpen() const;
    void InitiateNextStage();
    void InitCaretakerActions(TArray<UCaretakerActionComponent*> carettakeractions);
    void CloseAllEyes();
};
