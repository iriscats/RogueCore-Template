#pragma once
#include "CoreMinimal.h"

#include "PerkEquipEntry.generated.h"

USTRUCT(BlueprintType)
struct FPerkEquipEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid characterID;
    
    TArray<FGuid> PerkIDs;
    ROGUECORE_API FPerkEquipEntry();
};
