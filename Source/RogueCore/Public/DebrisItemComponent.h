#pragma once
#include "CoreMinimal.h"
#include "DebrisActorComponent.h"
#include "DebrisItemActorItem.h"
#include "EDebrisItemPass.h"
#include "IRandRange.h"
#include "DebrisItemComponent.generated.h"

class UDebrisPositioning;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDebrisItemComponent : public UDebrisActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Debris;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDebrisItemActorItem> Actors;
    EDebrisItemPass ItemPass;
    float InfluenceRange;
    float MinDistanceToImportantLocations;
    bool UseAmount;
    FIRandRange amount;
    int32 AmountSearchMultiplier;
    int32 ObjectiveAmountSearchMultiplier;
    UDebrisItemComponent(const FObjectInitializer& ObjectInitializer);
};
