#pragma once
#include "CoreMinimal.h"
#include "UsableComponent.h"
#include "ReloadSentryUsableComponent.generated.h"

class APlayerCharacter;
class ASentryGun;
class UAudioComponent;
class USoundBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UReloadSentryUsableComponent : public UUsableComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    ASentryGun* SentryGun;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText OutOfAmmoText;
    
    FText AmmoFullText;
    USoundBase* AudioOutOfAmmo;
    USoundBase* AudioReloading;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* ReloadingAudioComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool usable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Reloading, meta=(AllowPrivateAccess=true))
    bool bReloading;
    UAudioComponent* ReloadAudioComponent;
    float AmmoPerSec;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> OwningPlayerCharacter;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASentryGun* SentryGun;
    UReloadSentryUsableComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetOwningPlayerCharacter(APlayerCharacter* Player);
    void SetCanUse(bool isUsable);
    UFUNCTION()
    void OnRep_Reloading();
    void OnReloadAudioFinished();
};
