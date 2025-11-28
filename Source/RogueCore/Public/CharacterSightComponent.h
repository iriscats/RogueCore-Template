#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "UObject/UnrealType.h"
#include "ReplicatedCharacterData.h"
#include "CharacterSightComponent.generated.h"

class AActor;
class APlayerCharacter;
class IHealth;
class UHealth;
class ITargetable;
class UTargetable;
class UCharacterSightSensorBase;
class UPawnAfflictionComponent;
class UPrimitiveComponent;
class USimpleObjectInfoComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterSightComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTargetChangedSignature, AActor*, NewTarget, UPrimitiveComponent*, NewPrimitive);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTargetChangedSignature OnTargetChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetMaxDistance;
    TEnumAsByte<ECollisionChannel> TraceChannel;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> IgnoredActors;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    TWeakObjectPtr<AActor> targetActor;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> TargetPrimitive;
    TWeakObjectPtr<USimpleObjectInfoComponent> TargetInfo;
    TWeakObjectPtr<UPawnAfflictionComponent> TargetAfflictions;
    TScriptInterface<IHealth> TargetHealth;
    TScriptInterface<ITargetable> TargetTargetable;
    float TargetTime;
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UCharacterSightSensorBase>> TargetSensors;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FReplicatedCharacterData ReplicatedData;
    UCharacterSightComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_UpdateTarget(AActor* NewActor, UPrimitiveComponent* NewPrimitive);
    UFUNCTION(BlueprintCallable)
    void RemoveIgnoreActor(AActor* InActor);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetSightStartAndEnd(float InMaxDistance, FVector& OutStartLocation, FVector& OutEndLocation) const;
    void AddIgnoreActor(AActor* InActor);
};
