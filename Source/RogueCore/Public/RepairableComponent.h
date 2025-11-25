#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RepairedDelegateDelegate.h"
#include "RepairableComponent.generated.h"

class APlayerCharacter;
class UGemResourceData;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URepairableComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRepairedDelegate OnFullyRepairedEvent;
    
    FRepairedDelegate OnAllResourcesAquiredEvent;
    FRepairedDelegate OnRepairedEvent;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGemResourceData* RequiresCarriedResource;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ResourcesRequired, meta=(AllowPrivateAccess=true))
    int32 ResourcesRequired;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IsFullyRepaired;
    URepairableComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool TryRepair(APlayerCharacter* User);
    UFUNCTION(BlueprintCallable)
    void OnRep_ResourcesRequired();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetResourcesRequired() const;
    void Cheat_Repair();
};
