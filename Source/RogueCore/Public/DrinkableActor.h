#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnPickedUpelegateDelegate.h"
#include "DrinkableActor.generated.h"

class APlayerCharacter;
class UDrinkableDataAsset;
UCLASS(Abstract, Blueprintable)
class ADrinkableActor : public AActor {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPickedUpelegate OnPickedUp;

 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_DrinkableData, meta=(AllowPrivateAccess=true))
    UDrinkableDataAsset* DrinkableData;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool Filled;
    UFUNCTION(BlueprintCallable)
    void OnRep_DrinkableData();

 
    friend struct Z_Construct_UClass_ADrinkableActor_Statics;
    ADrinkableActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Pickup(APlayerCharacter* byCharacter);
    void Fill();
};
