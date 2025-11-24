#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpiderAnimInstance.h"
#include "CrawlerAnimInstance.generated.h"

class UAnimMontage;
UCLASS(Blueprintable, NonTransient)
class UCrawlerAnimInstance : public USpiderAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TotalProgressionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsInBallisticMove;
    float BallisticPitch;
    float ProgressionTime;
    float AttackMoveBlend;
    TArray<UAnimMontage*> HeadIdleBreakMontages;
    FVector2D IdleBreakTimeRange;
    UCrawlerAnimInstance();
};
