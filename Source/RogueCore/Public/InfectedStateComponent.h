#pragma once
#include "CoreMinimal.h"
#include "CharacterStateComponent.h"
#include "RandRange.h"
#include "InfectedStateComponent.generated.h"

class UAnimMontage;
class UFSDPhysicalMaterial;
class UPawnAffliction;
class USoundBase;
UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInfectedStateComponent : public UCharacterStateComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange CleanseAmount;
    
    USoundBase* AudioFreeOfInfection;
    UFSDPhysicalMaterial* InfectedPhysicalMaterial;
    UFSDPhysicalMaterial* DwarfFleshMaterial;
    UPawnAffliction* InfectedAffliction;
    UAnimMontage* InfectedMontage;
    UAnimMontage* InfectedAndBreakingFreeMontage;
    float BreakingFreeMontageDuration;
    float HoldToBreakTime;
    UInfectedStateComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Breakout();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveOnCleansing();
};
