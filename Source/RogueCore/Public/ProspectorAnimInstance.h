#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EProspectorRobotState.h"
#include "EnemyAnimInstance.h"
#include "ProspectorAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UProspectorAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector2D TiltResult;

    FVector2D LookingResult;
    EProspectorRobotState ProspectorState;
    float ArmBusyness;
    UProspectorAnimInstance(const FObjectInitializer& ObjectInitializer);
};
