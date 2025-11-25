#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "SaveGameIDInterface.h"
#include "SavableDataAsset.generated.h"

class UBuildRestriction;
UCLASS(Blueprintable)
class USavableDataAsset : public UDataAsset, public ISaveGameIDInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableDangerousSaveGameIDEditing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SavegameID;
    UBuildRestriction* BuildRestriction;
    USavableDataAsset();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGuid GetSaveGameID() const;
    // Fix for true pure virtual functions not being implemented
};
