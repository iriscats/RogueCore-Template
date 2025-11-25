#pragma once
#include "CoreMinimal.h"
#include "StructureActor.h"
#include "LockedRoomActor.generated.h"

class UBXEBlueprintControlledObjective;
UCLASS(Blueprintable)
class ALockedRoomActor : public AStructureActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBXEBlueprintControlledObjective* Objective;
    
    ALockedRoomActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetObjective(UBXEBlueprintControlledObjective* InObjective);
};
