#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PloverAttachmentComponent.generated.h"

class AFSDPawn;
class UPloverTargetSockets;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UPloverAttachmentComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_AttachTarget, meta=(AllowPrivateAccess=true))
    AFSDPawn* AttachTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPloverTargetSockets* AttachementSettings;
    float TargetAttachDistance;
    float InterpSpeed;
    UPloverAttachmentComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_AttachTarget();
    bool GetAttachLocation(AFSDPawn* Target);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AttachToTarget(AFSDPawn* Target);
};
