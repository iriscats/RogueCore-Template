#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "SaveGameIDInterface.h"
#include "SavablePrimaryDataAsset.generated.h"

class UBuildRestriction;
UCLASS(Blueprintable)
class USavablePrimaryDataAsset : public UPrimaryDataAsset, public ISaveGameIDInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FGuid SavegameID;

    UBuildRestriction* BuildRestriction;

    USavablePrimaryDataAsset();

    // Fix for true pure virtual functions not being implemented



public:
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BuildRestrictions;
    
    int32 PlatformRestrictions;
protected:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableDangerousSaveGameIDEditing;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SavegameID;
    UBuildRestriction* BuildRestriction;
    USavablePrimaryDataAsset();
    // Fix for true pure virtual functions not being implemented
};
