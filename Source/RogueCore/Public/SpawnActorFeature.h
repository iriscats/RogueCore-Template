#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EItemAdjustmentType.h"
#include "RoomFeature.h"
#include "Templates/SubclassOf.h"
#include "SpawnActorFeature.generated.h"

class AActor;
UCLASS(Blueprintable, EditInlineNew)
class USpawnActorFeature : public URoomFeature {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    TSubclassOf<AActor> ActorToSpawn;
    FVector AdjustmentDirection;
    EItemAdjustmentType Adjustment;
    FVector ScaleMin;
    FVector ScaleMax;
    FRotator RotationDelta;
    USpawnActorFeature();
};
