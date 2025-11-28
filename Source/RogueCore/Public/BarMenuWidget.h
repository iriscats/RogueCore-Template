#pragma once
#include "CoreMinimal.h"
#include "WindowWidget.h"
#include "BarMenuWidget.generated.h"

class ASpaceRigBar;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UBarMenuWidget : public UWindowWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASpaceRigBar> SpaceRigBar;
    
    UBarMenuWidget();
};
