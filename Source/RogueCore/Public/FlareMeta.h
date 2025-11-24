#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FlareMeta.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FFlareMeta {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Actor;
    
    float Inhibit;
    float Radius;
    float InvRadius;
    FVector Pos;
    bool Moving;
    ROGUECORE_API FFlareMeta();
};
