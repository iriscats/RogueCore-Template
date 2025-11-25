#pragma once
#include "CoreMinimal.h"
#include "CharacterStateComponent.h"
#include "EExitTrackMode.h"
#include "PipelineMovementData.h"
#include "TrackMovementStateComponent.generated.h"

class AZipLineConnector;
class UAudioComponent;
class UDialogDataAsset;
class USoundBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UTrackMovementStateComponent : public UCharacterStateComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* AudioStartComponent;
    
    UAudioComponent* AudioDuringComponent;
    UAudioComponent* AudioStopComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> AudioOnStart;
    TSoftObjectPtr<USoundBase> AudioOnDuring;
    TSoftObjectPtr<USoundBase> AudioOnStop;
    float AudioOnFadeOut;
    UDialogDataAsset* StateUpdateShout;
    float StateUpdateShoutFrequencySecsMin;
    float StateUpdateShoutFrequencySecsMax;
    float AudioDuringSlidingSpeedParam;
    float SpeedTarget;
    float SpeedMin;
    float SpeedMax;
    float AccelerationBase;
    float AccelerationMultiplier;
    float DecelerationMultiplier;
    float AccelerationOnSlopeMultiplier;
    float DecelerationOnSlopeMultiplier;
    float StoppingDeceleration;
    float StoppingDistance;
    TSoftClassPtr<AZipLineConnector> ConnectorClass;
    AZipLineConnector* Connector;
    EExitTrackMode ExitMode;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TrackMovementdata, meta=(AllowPrivateAccess=true))
    FPipelineMovementData TrackMovementData;
    UTrackMovementStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerExitMode(EExitTrackMode eMode);
    UFUNCTION(Reliable, Server)
    void ServerAddTemporaryAcceration(float Acceleration, float Duration);
    UFUNCTION(BlueprintCallable)
    void OnRep_TrackMovementdata(FPipelineMovementData& oldState);
    void JumpPressed();
};
