#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/HierarchicalInstancedStaticMeshComponent.h"
#include "DebrisInstances.generated.h"

class UDebrisBase;
UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDebrisInstances : public UHierarchicalInstancedStaticMeshComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDebrisBase* DebrisBase;
    
 
    int32 DebrisIndex;
    UDebrisInstances(const FObjectInitializer& ObjectInitializer);
};
