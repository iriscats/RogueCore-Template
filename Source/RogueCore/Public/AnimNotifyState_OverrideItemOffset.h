#pragma once
#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_OverrideItemOffset.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, MinimalAPI)
class UAnimNotifyState_OverrideItemOffset : public UAnimNotifyState {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CameraOffset;
    
    UAnimNotifyState_OverrideItemOffset();
};
