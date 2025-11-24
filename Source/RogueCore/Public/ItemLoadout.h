#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemLoadout.generated.h"

USTRUCT(BlueprintType)
struct FItemLoadout {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DebugSource;
    
    FGuid PrimaryWeapon;
    FGuid SecondaryWeapon;
    FGuid TraversalTool;
    FGuid ClassTool;
    FGuid Armor;
    FGuid Flare;
    FGuid MiningTool;
    FGuid Grenade;
    int32 IconIndex;
    ROGUECORE_API FItemLoadout();
};
