#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSDCloudSaveHandler.generated.h"

UCLASS(Blueprintable)
class UFSDCloudSaveHandler : public UObject {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 NumFailedSaves;
    
    UFSDCloudSaveHandler();
};
