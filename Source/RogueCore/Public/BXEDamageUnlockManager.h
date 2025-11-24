#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BXEDamageUnlockModifiers.h"
#include "BXEDamageUnlockManager.generated.h"

class APlayerCharacter;
UCLASS(Blueprintable)
class UBXEDamageUnlockManager : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<APlayerCharacter*, FBXEDamageUnlockModifiers> DamageUnlocks;
    
    UBXEDamageUnlockManager();
};
