#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "BXECompanionStateDelegateDelegate.h"
#include "CompanionDroneHologram.h"
#include "DeepPathfinderCharacter.h"
#include "EBXECompanionDroneState.h"
#include "NameDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "BXECompanionDrone.generated.h"

class AActor;
class ADroneDestinationMarker;
class UAnimSequence;
class UAudioComponent;
class UCappedResource;
class UDialogDataAsset;
class UPlayersNegotiationSphere;
class UResourceBank;
class USceneComponent;
class USingleUsableComponent;
class USkeletalMesh;
class USkeletalMeshComponent;
class USoundCue;
class USplineComponent;
class USplineMeshComponent;
class UStaticMesh;
class UUnlockCollectionTag;
class UUserWidget;
UCLASS(Blueprintable)
class ABXECompanionDrone : public ADeepPathfinderCharacter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* ArmSpline;
    
    UAudioComponent* MovementAudio;
    UAudioComponent* ArmExtensionNoise;
    UResourceBank* ResourceBank;
    USceneComponent* CableHead;
    USkeletalMeshComponent* CableHeadMesh;
    UAudioComponent* GrindingAudio;
    UAudioComponent* HackingAudio;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBXECompanionStateDelegate OnStateEntered;
    FBXECompanionStateDelegate OnStateLeft;
    FNameDelegate OnAiMessaged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FTransform ConnectorPoint;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DestinationLocation, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize DestinationLocation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompanionDroneHologram> Holograms;
    FName MovementAudioParam;
    FName GrinderSpinRateParam;
    UPlayersNegotiationSphere* PlayerNegotiationSphere;
    UUnlockCollectionTag* RewardCollectionTag;
    UUnlockCollectionTag* ArtifactCollectionTag;
    UUnlockCollectionTag* PotentExpeniteCollectionTag;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UUnlockCollectionTag*, FRandomStream> RewardRandomStreams;
    TArray<USplineMeshComponent*> MeshSegmentCashe;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USingleUsableComponent*> SyncedUseList;
    TSubclassOf<ADroneDestinationMarker> DestinationMarkerClass;
    ADroneDestinationMarker* DestinationMarker;
    USkeletalMesh* TentacleHeadMesh;
    UAnimSequence* SaluteAnim;
    TWeakObjectPtr<AActor> LookAtTarget;
    USoundCue* CallResponseCue;
    USoundCue* CableConnectCue;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAudioComponent> CableConnectInstance;
    UStaticMesh* ArmSegment;
    float CableRange;
    float CableExtensionTime;
    float MaxArmLength;
    float ArmSegmentLength;
    float ExtensionProgress;
    float ExtensionTurnHeadTowardsTargetPercentage;
    float SplineTangentPower;
    float CallResponseTime;
    float GrinderAcceleration;
    float GrinderFadeTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EBXECompanionDroneState State;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TrayOpen, meta=(AllowPrivateAccess=true))
    bool TrayOpen;
    bool PrintAudioParams;
    bool BlockLevelUpWhileDispensing;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_BeingDepositedTo, meta=(AllowPrivateAccess=true))
    bool BeingDepositedTo;
    FText Header_NegotiatingArtifact;
    FText Header_NegotiatingUpgrade;
    UDialogDataAsset* ShoutUpgradesWaiting;
    UDialogDataAsset* ShoutUpgradesLastActivation;
    float MinTimeBetweenConsecutiveShouts;
    float TimeOfLastShout;
 
    ABXECompanionDrone(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void StartNegotiation();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetState(EBXECompanionDroneState NewState);
    void SetPlayerNegotiationSphere(UPlayersNegotiationSphere* Sphere);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_MessageAi(FName Trigger);
    void OnTrayChanged();
 
    void OnResourceAdded(UCappedResource* Resource, float amount);
    UFUNCTION()
    void OnRep_TrayOpen();
    UFUNCTION()
    void OnRep_State(EBXECompanionDroneState oldState);
    UFUNCTION()
    void OnRep_DestinationLocation();
    UFUNCTION()
    void OnRep_BeingDepositedTo();
    void OnInsidePlayerChanged(int32 PlayerCount);
    void OnHologramEndUse(USingleUsableComponent* usable, UUserWidget* Widget, const FName& bone);
    void OnHologramEnabled(USingleUsableComponent* usable, UUserWidget* Widget, const FName& bone);
    void OnHologramDisabled(USingleUsableComponent* usable, UUserWidget* Widget, const FName& bone);
    void OnHologramBeginUse(USingleUsableComponent* usable, UUserWidget* Widget, const FName& bone);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EBXECompanionDroneState GetState() const;
    int32 GetActiveButtonCount() const;
    void CoupleHologram(USingleUsableComponent* usable, UUserWidget* Widget);
};
