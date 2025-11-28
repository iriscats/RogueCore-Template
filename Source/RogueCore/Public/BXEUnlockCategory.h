#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BXEUnlockCategory.generated.h"

UCLASS(Blueprintable)
class UBXEUnlockCategory : public UDataAsset {
    GENERATED_BODY()
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CategoryName;
    
    UBXEUnlockCategory();
};
