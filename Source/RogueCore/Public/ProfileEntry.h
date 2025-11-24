#pragma once
#include "CoreMinimal.h"
#include "ProfileEntry.generated.h"

class UObject;
USTRUCT(BlueprintType)
struct FProfileEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> Context;
    
    FString Category;
    float TimeSpent;
    ROGUECORE_API FProfileEntry();
};
