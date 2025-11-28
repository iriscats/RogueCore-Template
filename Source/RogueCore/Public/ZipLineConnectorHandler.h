#pragma once
#include "CoreMinimal.h"
#include "ZipLineConnectorHandler.generated.h"

class AZipLineConnector;
USTRUCT(BlueprintType)
struct FZipLineConnectorHandler {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AZipLineConnector> ConnectorClass;
    
    AZipLineConnector* Connector;
    ROGUECORE_API FZipLineConnectorHandler();
};
