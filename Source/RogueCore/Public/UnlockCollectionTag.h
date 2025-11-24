#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UnlockCollectionTag.generated.h"

class UBXEUnlockCollection;
UCLASS(Blueprintable)
class UUnlockCollectionTag : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBXEUnlockCollection* DefaultCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UBXEUnlockCollection* OverrideCollection;
    UUnlockCollectionTag();
};
