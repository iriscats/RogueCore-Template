#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "Templates/SubclassOf.h"
#include "AnimNotify_CameraShake.generated.h"

class UCameraShakeBase;
UCLASS(Blueprintable, CollapseCategories, MinimalAPI)
class UAnimNotify_CameraShake : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerRadius;
    
    float OuterRadius;
    bool ControllerOnly;
    TSubclassOf<UCameraShakeBase> CameraShake;
    UAnimNotify_CameraShake();
};
