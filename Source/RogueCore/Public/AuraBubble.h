#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Templates/SubclassOf.h"
#include "AuraBubble.generated.h"

class UPrimitiveComponent;
class USceneComponent;
class USphereComponent;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class AAuraBubble : public AActor {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USphereComponent* AuraShape;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStatusEffect>> AuraEffects;
    TArray<AActor*> ActorsInAura;
    bool RepelEnemies;
    float RepelInterval;
    TArray<TSubclassOf<AActor>> ClassFilter;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsActive, meta=(AllowPrivateAccess=true))
    bool IsActive;
    AAuraBubble(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_StopEffects();
    void Receive_StartEffects();
    UFUNCTION(BlueprintCallable)
    void OnRep_IsActive();
    void OnActorLeftAura(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnActorEnteredAura(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
