#pragma once
#include "CoreMinimal.h"
#include "EBXEOverclockType.h"
#include "SavablePrimaryDataAsset.h"
#include "BXEUnlockRarity.generated.h"

class URarityConditionBase;
class UUnlockVisualSettings;
UCLASS(Blueprintable)
class UBXEUnlockRarity : public USavablePrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponAttributes;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EBXEOverclockType OverclockType;
    UUnlockVisualSettings* VisualSettings;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URarityConditionBase*> SelectionConditions;
 
    FString RarityTitle;
    UBXEUnlockRarity();
};
