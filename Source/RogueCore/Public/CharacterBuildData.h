#pragma once
#include "CoreMinimal.h"

#include "UnlockableTypeData.h"
#include "CharacterBuildData.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FCharacterBuildData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PlayerName;
    
    FGuid PlayerCharacterID;
    int32 PlayerIndex;
    TArray<FUnlockableTypeData> UnlockRecords;
    TArray<FGuid> Enhancements;
    FCharacterBuildData();
};
