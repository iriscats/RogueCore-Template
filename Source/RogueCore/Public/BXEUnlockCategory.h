#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BXEUnlockCategory.generated.h"

UCLASS(Blueprintable)
class UBXEUnlockCategory : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CategoryName;
    
    UBXEUnlockCategory();
};
