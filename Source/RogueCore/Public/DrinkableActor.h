#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnPickedUpelegateDelegate.h"
#include "DrinkableActor.generated.h"

class APlayerCharacter;
class UDrinkableDataAsset;
UCLASS(Abstract, Blueprintable, NoExport)
class ADrinkableActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPickedUpelegate OnPickedUp;

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_DrinkableData, meta=(AllowPrivateAccess=true))
    UDrinkableDataAsset* DrinkableData;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool Filled;
    UFUNCTION(BlueprintCallable)
    void OnRep_DrinkableData();

private:
    friend struct Z_Construct_UClass_ADrinkableActor_Statics;
    ADrinkableActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Pickup(APlayerCharacter* byCharacter);
    void Fill();
};
