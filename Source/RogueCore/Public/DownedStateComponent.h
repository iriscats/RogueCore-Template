#pragma once
#include "CoreMinimal.h"
#include "CharacterStateComponent.h"
#include "DeathIntroSettings.h"
#include "EnableDownedBombUIDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "DownedStateComponent.generated.h"

class UDamageComponent;
UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDownedStateComponent : public UCharacterStateComponent {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDeathIntroSettings Intro;
    
    float DownedHealthLossPerSecond;
    float TerrainRemovedFallThreshold;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool DownedBombActive;
    bool PlayIntroSequence;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDamageComponent* DownedBombDamage;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableDownedBombUIDelegate OnEnableDownedBombUIEvent;
    UDownedStateComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void TriggerDownedBombDamage();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_TriggerDownedBomb();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_TriggerDownedBomb();
    UDamageComponent* CreateDownedBombDamage(TSubclassOf<UDamageComponent> DamageClass);
};
