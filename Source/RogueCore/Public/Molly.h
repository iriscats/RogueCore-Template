#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DelegateDelegate.h"
#include "MULE.h"
#include "Molly.generated.h"

class APlayerCharacter;
class UDialogDataAsset;
class UNiagaraSystem;
class UOutlineComponent;
class UResourceBank;
UCLASS(Abstract, Blueprintable, NoExport)
class ROGUECORE_API AMolly : public AMULE {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCalledByDelegate, APlayerCharacter*, InPlayer);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCalledByDelegate OnCalledByChanged;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UResourceBank* ResourceBank;
    UOutlineComponent* OutlineComponent;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnReachedDropShip;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShowButtonDelay;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CalledBy, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> CalledBy;
    AMolly(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetOpenForDeposit(bool Open);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void SetGotoDropShip(const FVector& Location);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetCalledBy(APlayerCharacter* InPlayer);
    UFUNCTION()
    void OnRep_CalledBy();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UDialogDataAsset* GetCallingShout() const;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnableButton();
    void AddTrayEffect(UNiagaraSystem* Effect, int32 numberOfTraysAffected);
};
