#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterStateComponent.h"
#include "DamageData.h"
#include "ZipLine.h"
#include "ZipLineConnectorHandler.h"
#include "ZipLineStateComponent.generated.h"

class AZipLineProjectile;
class UAudioComponent;
class UDialogDataAsset;
class UPlayerHealthComponent;
class USoundBase;
UCLASS(Abstract, Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UZipLineStateComponent : public UCharacterStateComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FZipLineConnectorHandler ZipLineConnector;
    
    float VerticalOffset;
    float HorizontalOffset;
    float TravelSpeed;
    float AccelAndDecelAlpha;
    float JumpForce;
    float SpeedBoostActivationDuration;
    float SpeedBoostActivionMinAngle;
    float BaseSpeedBoost;
    float AdditionalSpeedBoostPerAngle;
    float SpeedBoostCoolDownDuration;
    float AccelerationAlpha;
    float DecelerationAlpha;
    float MinStartDistanceToEnd;
    float ReleaseDistance;
    bool bCanActivateSpeedBoost;
    bool bShowSpeedBoostActivator;
    float SpeedBoostActivationProgress;
    USoundBase* AudioOnStart;
    USoundBase* AudioOnDuring;
    USoundBase* AudioOnChangingDirection;
    USoundBase* AudioOnStop;
    USoundBase* AudioOnSpeedBoostActivated;
    UDialogDataAsset* ShoutStartUsing;
    UDialogDataAsset* ShoutSpeedBoostActivated;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AZipLineProjectile* ZipLineProjectile;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ZipLine, meta=(AllowPrivateAccess=true))
    FZipLine ZipLine;
    float DamageBeforeFalling;
    float FriendlyFireModifier;
    float DamageResetTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* AudioComponent;
    UZipLineStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetSpeedBoostActivated(bool InBoostActivated);
    UFUNCTION(Reliable, Server)
    void ServerJumpPressed(bool JumpForward);
    UFUNCTION(Reliable, Server)
    void ServerForwardInputChanged(float Input);
    UFUNCTION(Reliable, Server)
    void ServerChangeDirection();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveSpeedBoostDeactivated();
    void ReceiveSpeedBoostActivated();
    UFUNCTION(BlueprintCallable)
    void OnRep_ZipLine();
    void OnPlayerHit(UPlayerHealthComponent* playerHealth, float RawDamage, float actualDamage, const FDamageData& DamageData, bool anyHealthLost);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSpeedBoostActivated() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetJumpVector(FVector LookVector, FVector CurrentVelocity);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_SpeedBoostChanged(bool bActive);
};
