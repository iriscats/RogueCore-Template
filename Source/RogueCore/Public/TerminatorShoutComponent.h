#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/UnrealType.h"
#include "DelegateDelegate.h"
#include "ETerminatorShoutState.h"
#include "TerminatorShoutState.h"
#include "TerminatorTalkMaterial.h"
#include "TerminatorShoutComponent.generated.h"

class UAudioComponent;
class UMeshComponent;
class UPointLightComponent;
class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTerminatorShoutComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    UMeshComponent* OwnerMesh;

    UAudioComponent* ShoutInstance;

    UTerminatorShoutComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)

    void SetShoutState(ETerminatorShoutState State, float delayShout);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTerminatorShoutState> States;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnShoutStarted;
    FDelegate OnShoutEnded;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTerminatorTalkMaterial> TalkMaterials;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPointLightComponent* TalkLight;
    float MaxRadius;
    float MaxIntensity;
    FName SoundOriginSocket;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshComponent* OwnerMesh;
    UAudioComponent* ShoutInstance;
    UTerminatorShoutComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetShoutState(ETerminatorShoutState State, float delayShout);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShoutStart();
    UFUNCTION(BlueprintCallable)
    void OnShoutInstancePlayStateChanged(EAudioComponentPlayState PlayState);
    void OnShoutEnd();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayShout(USoundCue* Shout);
};
