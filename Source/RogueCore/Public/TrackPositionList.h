#pragma once
#include "CoreMinimal.h"

#include "TrackPositionList.generated.h"

class UGemTracker;
class UMaterialInstanceDynamic;
USTRUCT(BlueprintType)
struct FTrackPositionList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TrackName;
    
    TArray<FVector4> Positions;
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UGemTracker>> Trackers;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UMaterialInstanceDynamic>> DynamicMaterials;
    ROGUECORE_API FTrackPositionList();
};
