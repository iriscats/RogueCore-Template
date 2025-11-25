#pragma once
#include "CoreMinimal.h"
#include "ECaveEntranceType.h"
#include "GenerationItem.h"
#include "CaveEntrance.generated.h"

class UCaveEntranceComponent;
UCLASS(Blueprintable, CollapseCategories, NoExport)
class ACaveEntrance : public AGenerationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCaveEntranceComponent* CaveEntranceComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECaveEntranceType EntranceType;
 
    bool HasBeenConverted;
    ACaveEntrance(const FObjectInitializer& ObjectInitializer);
};
