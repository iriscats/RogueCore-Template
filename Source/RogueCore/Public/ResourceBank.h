#pragma once
#include "CoreMinimal.h"
#include "UsableComponentBase.h"
#include "ResourceBank.generated.h"

class AFSDGameState;
class APlayerCharacter;
class UDialogDataAsset;
class UResourceBankFilter;
class UResourceData;
class USoundBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UResourceBank : public UUsableComponentBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    AFSDGameState* GameState;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    UResourceBankFilter* ResourceFilter;

    float DepositesPerSecond;

    float DepositeAmount;

    bool CanGetStrict;

    bool AddToTeamInventory;

    USoundBase* AudioBeginDepositing;

    USoundBase* AudioDepositing;

    USoundBase* AudioEndDepositing;

    UDialogDataAsset* ShoutBeginDepositing;

    UResourceBank(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FResourceEvent, UResourceData*, Resource, float, amount);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FResourceBankEvent, APlayerCharacter*, User);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResourceBankEvent OnBeginDeposite;
    FResourceBankEvent OnDepositing;
    FResourceBankEvent OnEndDeposite;
    FResourceEvent OnResourceDeposited;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool OpenForDeposit;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFSDGameState* GameState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceBankFilter* ResourceFilter;
    float DepositesPerSecond;
    float DepositeAmount;
    bool CanGetStrict;
    bool AddToTeamInventory;
    USoundBase* AudioBeginDepositing;
    USoundBase* AudioDepositing;
    USoundBase* AudioEndDepositing;
    UDialogDataAsset* ShoutBeginDepositing;
    UResourceBank(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_Depositing(APlayerCharacter* Character);
};
