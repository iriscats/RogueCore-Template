#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UpperBodyCharacterAnimationSet.generated.h"

class UAnimSequence;
UCLASS(Blueprintable)
class UUpperBodyCharacterAnimationSet : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* TP_Idle;
    
    UAnimSequence* TP_Jump;
    UAnimSequence* TP_Sprint;
    UAnimSequence* TP_Walk;
    UAnimSequence* TP_Run;
    UUpperBodyCharacterAnimationSet();
};
