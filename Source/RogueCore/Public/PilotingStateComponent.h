#pragma once
#include "CoreMinimal.h"
#include "CharacterStateComponent.h"
#include "PilotingStateComponent.generated.h"

class AActor;
UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPilotingStateComponent : public UCharacterStateComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Vehicle, meta=(AllowPrivateAccess=true))
    AActor* Vehicle;
    
    UPilotingStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_MoveRight(float Value);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_MoveForward(float Value);
    UFUNCTION(BlueprintCallable)
    void OnRep_Vehicle();
};
