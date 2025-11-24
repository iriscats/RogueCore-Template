#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TesterName.generated.h"

USTRUCT(BlueprintType)
struct FTesterName : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SteamID;
    
    FString SteamProfileName;
    ROGUECORE_API FTesterName();
};
