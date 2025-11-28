#pragma once
#include "CoreMinimal.h"
#include "SpecialEventSpawner.h"
#include "SimpleSpecialEventSpawner.generated.h"

class AActor;
class UDebrisPositioning;
UCLASS(Blueprintable, EditInlineNew)
class USimpleSpecialEventSpawner : public USpecialEventSpawner {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> EventActor;
    float EventAvoidanceRadius;
    USimpleSpecialEventSpawner();
};
