#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "DrinkableBarSlot.h"
#include "EHolidayType.h"
#include "HolidayMeshItems.h"
#include "Templates/SubclassOf.h"
#include "SpaceRigBar.generated.h"

class ADrinkableActor;
class APlayerCharacter;
class UBarMenuWidget;
class UBoxComponent;
class UDrinkableDataAsset;
class UInstantUsable;
UCLASS(Abstract, Blueprintable)
class ASpaceRigBar : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDrinkableSignature, UDrinkableDataAsset*, drinkable);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDrinkableSignature OnNewDrinkableSpecial;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstantUsable* BarUsable;
    UBoxComponent* BarUsableCollider;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBarMenuWidget> BarMenuWidget;
    TArray<FVector> DrinkServingLocations;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FDrinkableBarSlot> DrinkableBarSlots;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DrinkableSpecial, meta=(AllowPrivateAccess=true))
    UDrinkableDataAsset* DrinkableSpecial;
    TMap<EHolidayType, FHolidayMeshItems> HolidayComponentMap;
    ASpaceRigBar(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SpawnDrinkables(UDrinkableDataAsset* drinkable, APlayerCharacter* User);
    UFUNCTION(BlueprintCallable)
    void SetVisibilityOfHolidayMeshes();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveFinishedSpawningDrinkables(UDrinkableDataAsset* DrinkableData, APlayerCharacter* Customer);
    void ReceiveDrinkableSpawned(ADrinkableActor* drinkable, APlayerCharacter* Customer, int32 LocationIndex);
    void ReceiveBeginSpawningDrinkables(UDrinkableDataAsset* DrinkableData, APlayerCharacter* Customer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float PlayNegativeAnim();
    void PlayBartenderTip(APlayerCharacter* User);
    void PayTip(APlayerCharacter* Character, int32 Credits);
    UFUNCTION()
    void OnRep_DrinkableSpecial();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool HasUnclaimedDrinkables() const;
    bool HasSpaceForMoreDrinkables() const;
    int32 GetAvailableDrinkableSlots() const;
};
