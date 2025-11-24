#pragma once
#include "CoreMinimal.h"
#include "ArmorHealthSubItem.generated.h"

USTRUCT(BlueprintType)
struct FArmorHealthSubItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Health;
    
    FName BoneName;
    TArray<FName> AdditionalBones;
    FName OptionalFXSocket;
    ROGUECORE_API FArmorHealthSubItem();
};
