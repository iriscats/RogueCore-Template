#pragma once
#include "CoreMinimal.h"
#include "UObject/UnrealType.h"
#include "UObject/UnrealType.h"
#include "Layout/Margin.h" 
#include "Components/PanelSlot.h"
#include "Components/SlateWrapperTypes.h"
#include "BasicSlot.generated.h"

UCLASS(Blueprintable)
class BASICUI_API UBasicSlot : public UPanelSlot {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateChildSize Size;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin Padding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EVerticalAlignment> VerticalAlignment;
    
public:
    UBasicSlot();

};

