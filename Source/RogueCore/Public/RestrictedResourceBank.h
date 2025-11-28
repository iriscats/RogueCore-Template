#pragma once
#include "CoreMinimal.h"
#include "ResourceBank.h"
#include "RestrictedResourceBank.generated.h"

class UResourceData;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URestrictedResourceBank : public UResourceBank {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* RequiredResource;
    
    URestrictedResourceBank(const FObjectInitializer& ObjectInitializer);
};
