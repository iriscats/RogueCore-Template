#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BootUpDelegateDelegate.h"
#include "EInputKeys.h"
#include "EventStarterButton.generated.h"

class APlayerCharacter;
class USceneComponent;
class USingleUsableComponent;
UCLASS(Blueprintable, NoExport)
class AEventStarterButton : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))

    bool IsEventActive;

    AEventStarterButton(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USingleUsableComponent* usable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBootUpDelegate OnBootupEvent;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Booted, meta=(AllowPrivateAccess=true))
    bool Booted;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_OpenForUse, meta=(AllowPrivateAccess=true))
    bool IsOpenForUse;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IsEventActive;
    AEventStarterButton(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetIsEventActive(bool NewIsEventActive);
    void OnUseProgress(float Progress);
    UFUNCTION()
    void OnRep_OpenForUse();
    UFUNCTION()
    void OnRep_Booted();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOpenedForUse(bool wasOpened);
    void OnBooted();
    void CloseForUse(APlayerCharacter* User, EInputKeys Key);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void BootUpEvent();
};
