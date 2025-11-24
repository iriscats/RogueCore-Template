#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ELaserPointerTargetType.h"
#include "LaserPointerData.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FLaserPointerData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FText Name;
    
    FText Description;
    FLinearColor Color;
    UTexture2D* Icon;
    ELaserPointerTargetType TargetType;
    FGuid SavegameID;
    ROGUECORE_API FLaserPointerData();
};
