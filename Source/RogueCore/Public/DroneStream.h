#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "DroneStream.generated.h"

class ABosco;
class UCapsuleComponent;
class UPrimitiveComponent;
class USceneComponent;
UCLASS(Blueprintable)
class ADroneStream : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;

    UCapsuleComponent* Collision;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckStartOverlaps;
    bool CheckEndOverlaps;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_OnAbilityDataSet();
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ABosco* GetBosco() const;

 
    friend struct Z_Construct_UClass_ADroneStream_Statics;
    ADroneStream(const FObjectInitializer& ObjectInitializer);
};
