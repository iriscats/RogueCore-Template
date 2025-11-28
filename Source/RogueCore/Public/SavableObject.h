#pragma once
#include "CoreMinimal.h"

#include "UObject/Object.h"
#include "SavableObject.generated.h"

UCLASS(Blueprintable)
class USavableObject : public UObject {
    GENERATED_BODY()
    

public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableDangerousSaveGameIDEditing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SavegameID;
    USavableObject();
};
