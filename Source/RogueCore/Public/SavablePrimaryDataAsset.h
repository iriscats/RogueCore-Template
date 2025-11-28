#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "SaveGameIDInterface.h"
#include "SavablePrimaryDataAsset.generated.h"

class UBuildRestriction;
UCLASS(Blueprintable)
class USavablePrimaryDataAsset : public UPrimaryDataAsset, public ISaveGameIDInterface {
    GENERATED_BODY()
    

public:
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BuildRestrictions;
    
    int32 PlatformRestrictions;
 
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableDangerousSaveGameIDEditing;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SavegameID;
    UBuildRestriction* BuildRestriction;
    USavablePrimaryDataAsset();
    // Fix for true pure virtual functions not being implemented
};
