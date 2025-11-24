#pragma once
#include "CoreMinimal.h"
#include "DebrisItemComponent.h"
#include "Templates/SubclassOf.h"
#include "BXEObjectiveDebrisItemComponent.generated.h"

class UBXEBlueprintControlledObjective;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBXEObjectiveDebrisItemComponent : public UDebrisItemComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBXEBlueprintControlledObjective> objectiveClass;
    
    UBXEObjectiveDebrisItemComponent(const FObjectInitializer& ObjectInitializer);
};
