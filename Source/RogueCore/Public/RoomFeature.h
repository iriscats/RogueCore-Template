#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RoomFeature.generated.h"

class URoomFeature;
UCLASS(Blueprintable, DefaultToInstanced, EditInlineNew)
class URoomFeature : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URoomFeature*> RoomFeatures;
    
    URoomFeature();
};
