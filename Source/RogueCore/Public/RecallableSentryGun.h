#pragma once
#include "CoreMinimal.h"
#include "RecallableActor.h"
#include "Templates/SubclassOf.h"
#include "RecallableSentryGun.generated.h"

class APlayerCharacter;
class ASentryGun;
UCLASS(Abstract, Blueprintable, NoExport)
class ARecallableSentryGun : public ARecallableActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSentryIndexChanged, int32, Index);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSentryIndexChanged OnSentryIndexChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SentryIndex, meta=(AllowPrivateAccess=true))
    int32 SentryIndex;
    ARecallableSentryGun(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveOnSentryReady(ASentryGun* SentryGun, APlayerCharacter* PlayerCharacter);
    UFUNCTION(BlueprintCallable)
    void OnRep_SentryIndex();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    void GetStateDescription(FText& Description) const;
    TSubclassOf<ASentryGun> GetSentryGunClass() const;
    ASentryGun* GetSentryGun();
};
