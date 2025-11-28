#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DebrisSet.generated.h"

class UDebrisBase;
UCLASS(Blueprintable)
class UDebrisSet : public UDataAsset {
    GENERATED_BODY()
    

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UDebrisBase>> Debris;

    UDebrisSet();

};
