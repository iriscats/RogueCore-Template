#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "OnCurrencyChangedDelegate.h"
#include "OnCurrencyCreatedDelegate.h"
#include "BarSubSystem.generated.h"

class AOmegaBartender;
class UDrinkableDataAsset;
class UObject;
class UResourceData;
UCLASS(Blueprintable)
class ROGUECORE_API UBarSubSystem : public UWorldSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCurrencyChanged OnCurrencyChanged;
    
    FOnCurrencyCreated OnCurrencyCreated;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AOmegaBartender* Bartender;
    UBarSubSystem();
    UFUNCTION(BlueprintCallable)
    void SetBartender(AOmegaBartender* aBartender);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool HasEnoughCurrency(const UObject* WorldContextObject, UResourceData* Currency, int32 amount);
    bool HasCollectiveResource(const UObject* WorldContextObject, UResourceData* Data);
    static UResourceData* GetGymCurrencyData(const UObject* WorldContextObject, int32 Index);
    static int32 GetGymCurrencyAmount(const UObject* WorldContextObject, int32 Index);
    static int32 GetCollectiveResourceIndex(const UObject* WorldContextObject, UResourceData* Data);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AOmegaBartender* GetBartender() const;
    static TArray<UResourceData*> GetAllGymCurrencyData(const UObject* WorldContextObject);
    static TArray<int32> GetAllGymCurrencyAmount(const UObject* WorldContextObject);
    static bool DeductCurrency(const UObject* WorldContextObject, UDrinkableDataAsset* Data);
    void AddInternalCurrency(const UObject* WorldContextObject, UResourceData* Data, int32 amount);
    static void AddCurrency(const UObject* WorldContextObject, UResourceData* Currency, int32 amount);
};
