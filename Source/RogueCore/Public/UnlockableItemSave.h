#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UnlockableItemSave.generated.h"

USTRUCT(BlueprintType)
struct FUnlockableItemSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGuid> Unlocked;

    ROGUECORE_API FUnlockableItemSave();
protected:
};
