#pragma once
#include "CoreMinimal.h"
#include "PickaxePartItem.h"
#include "PickaxeMeshPart.generated.h"

class UStaticMesh;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UPickaxeMeshPart : public UPickaxePartItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> mesh;
    
    UPickaxeMeshPart();
};
