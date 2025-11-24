#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TemporaryBuff.generated.h"

class APlayerCharacter;
class UTexture2D;
UCLASS(Abstract, Blueprintable)
class UTemporaryBuff : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FText Description;

    

    TSoftObjectPtr<UTexture2D> Icon;

    bool ActivatesOnlyOnceWhenDrinking;

    bool IsTodaysSpecialBuff;

    UTemporaryBuff();

    UFUNCTION(BlueprintCallable, BlueprintPure)

    bool GetActivateOnlyWhenDrinking() const;

    UFUNCTION(BlueprintCallable, BlueprintPure=false)

    void DeActivateBuff(APlayerCharacter* Player) const;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    TSoftObjectPtr<UTexture2D> Icon;
    bool ActivatesOnlyOnceWhenDrinking;
    bool IsTodaysSpecialBuff;
    UTemporaryBuff();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetActivateOnlyWhenDrinking() const;
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void DeActivateBuff(APlayerCharacter* Player) const;
    void ActivateBuff(APlayerCharacter* Player) const;
};
