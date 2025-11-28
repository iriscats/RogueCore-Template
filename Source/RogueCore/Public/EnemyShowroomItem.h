#pragma once
#include "CoreMinimal.h"
#include "EShowroomScaling.h"
#include "ShowroomItem.h"
#include "EnemyShowroomItem.generated.h"

UCLASS(Blueprintable)
class AEnemyShowroomItem : public AShowroomItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EShowroomScaling Scaling;

 
    AEnemyShowroomItem(const FObjectInitializer& ObjectInitializer);
};
