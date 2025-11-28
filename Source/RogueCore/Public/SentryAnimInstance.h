#pragma once
#include "CoreMinimal.h"
#include "SpiderAnimInstance.h"
#include "SentryAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROGUECORE_API USentryAnimInstance : public USpiderAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Sway;
    
    float Surge;
    USentryAnimInstance(const FObjectInitializer& ObjectInitializer);
};
