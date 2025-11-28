#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoomFeature.h"
#include "Templates/SubclassOf.h"
#include "SpawnTriggerFeature.generated.h"

class AActor;
UCLASS(Blueprintable, EditInlineNew)
class USpawnTriggerFeature : public URoomFeature {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> TriggerClass;
    
    FTransform Transform;
    FName Message;
    USpawnTriggerFeature();
};
