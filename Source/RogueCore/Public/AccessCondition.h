#pragma once
#include "CoreMinimal.h"
#include "SavableDataAsset.h"
#include "AccessCondition.generated.h"

class UAccessCondition;
class UDialogDataAsset;
class USoundCue;
UCLASS(Blueprintable)
class ROGUECORE_API UAccessCondition : public USavableDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DenyText;
    
    TSoftObjectPtr<UDialogDataAsset> DenyShout;
    TSoftObjectPtr<USoundCue> DenySound;
    TArray<UAccessCondition*> LinkedConditions;
    UAccessCondition();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UAccessCondition*> GetLinkedConditions() const;
    FText GetDenyText() const;
    TSoftObjectPtr<USoundCue> GetDenySound() const;
    TSoftObjectPtr<UDialogDataAsset> GetDenyShout() const;
};
