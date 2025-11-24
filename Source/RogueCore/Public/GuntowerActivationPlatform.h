#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "OnFinishedDelegate.h"
#include "PlayersInsideChangedDelegate.h"
#include "ProgressUpdatedDelegate.h"
#include "GuntowerActivationPlatform.generated.h"

class AFSDPlayerState;
class AGuntowerModule;
class UCapsuleComponent;
class UHealthComponentBase;
class UPrimitiveComponent;
class USceneComponent;
class UStaticMeshComponent;
UCLASS(Blueprintable, NoExport)
class AGuntowerActivationPlatform : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))

    AGuntowerModule* AssignedModule;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsShutDown, meta=(AllowPrivateAccess=true))

    bool IsShutDown;

    AGuntowerActivationPlatform(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UStaticMeshComponent* STMesh;
    UCapsuleComponent* Trigger;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProgressUpdated OnProgressUpdatedDelegate;
    FPlayersInsideChanged OnPlayersInsideChangedDelegate;
    FOnFinished OnProgressFilled;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AGuntowerModule* AssignedModule;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DoneAt;
    float DisabledTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_PlayersInside, meta=(AllowPrivateAccess=true))
    int32 playersInside;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Disabled, meta=(AllowPrivateAccess=true))
    bool Disabled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsShutDown, meta=(AllowPrivateAccess=true))
    bool IsShutDown;
    AGuntowerActivationPlatform(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ShutDown();
    void SetPlatformActive(bool IsActive);
    UFUNCTION(BlueprintCallable)
    void ReEnable();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayerSteppedOn(int32 CurrentCount);
    void PlayerSteppedOff(int32 CurrentCount);
    void PlayerInsideRevived();
    void PlayerInsideDied(UHealthComponentBase* Health);
    void OnShutDown();
    UFUNCTION()
    void OnRep_PlayersInside(int32 OldCount);
    UFUNCTION()
    void OnRep_IsShutDown();
    UFUNCTION()
    void OnRep_Disabled();
    void OnPlayersInsideChanged(int32 NewPlayersInside);
    void OnPlayerLeave(AFSDPlayerState* PlayerState);
    void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    void OnFinished();
    void OnDisabledChanged(bool IsDisabled);
    void ModuleDestroyed(UHealthComponentBase* Health);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPlayerCount() const;
    AGuntowerModule* GetAssignedModule() const;
    void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    bool CanWidgetAppear() const;
    void AssignModule(AGuntowerModule* towerModule);
};
