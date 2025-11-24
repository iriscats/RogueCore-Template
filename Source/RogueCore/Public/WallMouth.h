#pragma once
#include "CoreMinimal.h"
#include "FSDPawn.h"
#include "WallMouth.generated.h"

class UWallMouthAnimInstance;
UCLASS(Blueprintable, NoExport)
class AWallMouth : public AFSDPawn {
    GENERATED_BODY()

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWallMouthAnimInstance* AnimInstance;
    
    AWallMouth(const FObjectInitializer& ObjectInitializer);
};
