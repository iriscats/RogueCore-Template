#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "SaveGameIDInterface.h"
#include "CategoryID.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UCategoryID : public UDataAsset, public ISaveGameIDInterface {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SavegameID;
    
    UCategoryID();
    // Fix for true pure virtual functions not being implemented
};
