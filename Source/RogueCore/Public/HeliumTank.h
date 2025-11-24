#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EInputKeys.h"
#include "PitchedUsers.h"
#include "HeliumTank.generated.h"

class AHeliumTank;
class APlayerCharacter;
class UAudioComponent;
class UCurveFloat;
UCLASS(Blueprintable, NoExport)
class AHeliumTank : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))

    AHeliumTank* Leader;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* PitchCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_PitchedUsers, meta=(AllowPrivateAccess=true))
    TArray<FPitchedUsers> PitchedUsers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AHeliumTank* Leader;
    AHeliumTank(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnUsedBy(APlayerCharacter* User, EInputKeys Key);
    void OnShoutStarted(APlayerCharacter* Player, UAudioComponent* Audio);
    UFUNCTION()
    void OnRep_PitchedUsers();
};
