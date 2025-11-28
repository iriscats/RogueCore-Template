#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "StairSettings.generated.h"

class UStaticMesh;
UCLASS(Blueprintable)
class UStairSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LineTraceOffset;
    
    UStaticMesh* TopStairMesh;
    UStaticMesh* StairBody;
    UStaticMesh* BottomStairMesh;
    FVector CollisionOffset;
    float SegmentLenght;
    float Inclination;
    float MaxLength;
    float PreferredLenght;
    float StairWidth;
    UStairSettings();
};
