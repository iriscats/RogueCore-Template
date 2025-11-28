#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameEventAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UGameEventAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StageProgress;
    
    bool IsEventActive;
    bool AreEventStartersActive;
    bool EventFailed;
    UGameEventAnimInstance();
};
