#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EDroppableOutpostState.h"
#include "Templates/SubclassOf.h"
#include "DroppableOutpost.generated.h"

class ADroppableOutpost;
class UAutoCarverComponent;
class UCurveFloat;
class UObject;
UCLASS(Blueprintable)
class ROGUECORE_API ADroppableOutpost : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DropHeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAutoCarverComponent* AutoCarver;
    UCurveFloat* DepartCurve;
    float CarverRotationSpeed;
    FVector CarverScale;
    float DepartureTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector StartLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EDroppableOutpostState State;
    float DrillSpeed;
    float FreeFallAcceleration;
    float FreeFallSpeed;
    ADroppableOutpost(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StartDrilling();
    void PrepForTakeOff();
    UFUNCTION(BlueprintCallable)
    void OnRep_State();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPrepForTakeOff();
    void OnDroppodImpact();
    void OnDrillingStarted();
    void OnDeparting();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ADroppableOutpost* DropOutpostToMission(UObject* WorldContextObject, TSubclassOf<ADroppableOutpost> podClass, const FVector& Location);
    void Depart();
};
