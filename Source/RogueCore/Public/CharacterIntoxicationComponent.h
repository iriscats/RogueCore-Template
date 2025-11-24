#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CountDownFloat.h"
#include "EDrinkableAlcoholStrength.h"
#include "EIntoxicationState.h"
#include "LerpingPercent.h"
#include "CharacterIntoxicationComponent.generated.h"

class APlayerCharacter;
class UCurveFloat;
class UDrinkableDataAsset;
UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterIntoxicationComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPassOutDrunkSignature, APlayerCharacter*, Player);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIntoxicationProgressSignature, APlayerCharacter*, Player, float, Progress);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntoxicationProgressSignature OnIntoxicationChanged;
    FPassOutDrunkSignature OnPassOutDrunk;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    EIntoxicationState CurrentState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FLerpingPercent IntoxicationPercent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IntoxicationLerpSpeed;
    float TimeDrunk;
    FCountDownFloat SoberingUpCoolDown;
    uint8 SoberingPercent;
    UCharacterIntoxicationComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveStateChange(EIntoxicationState NewState);
    void ReceivePassOutDrunk();
    void ReceiveDrunkTick(float DeltaTime, float DrunkTime);
    void ReceiveDrunkEnd();
    void ReceiveDrunkBegin();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPassOutDrunk() const;
    bool IsOnSpaceRig() const;
    bool IsLocallyControlled() const;
    bool IsDrunk() const;
    bool HasAuthority() const;
    float GetSoberingUpCoolDown() const;
    float GetIntoxicationProgressMapped(UCurveFloat* Curve) const;
    float GetIntoxicationProgress() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetAlcoholPct(EDrinkableAlcoholStrength Strength) const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Consume(UDrinkableDataAsset* drinkable);
    void ClearIntoxication();
};
