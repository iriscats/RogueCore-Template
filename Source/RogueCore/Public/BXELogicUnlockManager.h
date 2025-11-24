#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BXELogicUnlockManager.generated.h"

class UBXELogicUnlockComponent;
UCLASS(Blueprintable)
class UBXELogicUnlockManager : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UBXELogicUnlockComponent*> LogicUnlocks;
    
    UBXELogicUnlockManager();
};
