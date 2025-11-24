#pragma once
#include "CoreMinimal.h"
#include "EDialogRestriction.h"
#include "DialogStruct.generated.h"

class USoundBase;
USTRUCT(BlueprintType)
struct ROGUECORE_API FDialogStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    FText Text;
    TSoftObjectPtr<USoundBase> Audio;
    TSoftObjectPtr<USoundBase> Audio_Voice02;
    EDialogRestriction Restriction;
    float Weight;
    FDialogStruct();
};
