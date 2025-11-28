#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockConditionBase.h"
#include "ECategoryConditionListMode.h"
#include "SoloDroneHasUnlockCategoryCondition.generated.h"

class UBXEUnlockCategory;
UCLASS(Blueprintable, EditInlineNew)
class USoloDroneHasUnlockCategoryCondition : public UBXEUnlockConditionBase {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBXEUnlockCategory*> Categories;
    
    ECategoryConditionListMode ListMode;
    USoloDroneHasUnlockCategoryCondition();
};
