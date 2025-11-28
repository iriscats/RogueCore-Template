#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockGenericBase.h"
#include "BXEUnlockGeneric.generated.h"

class UBXEUnlockAction;
class UWeaponTagBase;
UCLASS(Blueprintable)
class UBXEUnlockGeneric : public UBXEUnlockGenericBase {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UBXEUnlockAction*> Unlocks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UWeaponTagBase*> WeaponTagCache;
    UBXEUnlockGeneric();
};
