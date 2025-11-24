#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EActivityType.h"
#include "GameActivitySubTask.h"
#include "GameActivityType.generated.h"

UCLASS(Blueprintable)
class UGameActivityType : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ActivityId;
    
    EActivityType ActivityType;
    TArray<FGameActivitySubTask> SubTasks;
    UGameActivityType();
};
