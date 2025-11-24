#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DamagePartition.h"
#include "DamageLoggingItem.generated.h"

USTRUCT(BlueprintType)
struct FDamageLoggingItem : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Instigator;
    
    FString Causer;
    FString CauserOwner;
    FString Target;
    float TotalDamage;
    float Damage;
    TArray<FDamagePartition> DamagePartitions;
    float Timestamp;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 CritLevel;
    bool WeakpointHit;
    ROGUECORE_API FDamageLoggingItem();
};
