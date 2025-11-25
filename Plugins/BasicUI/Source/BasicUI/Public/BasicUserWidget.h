#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Blueprint/UserWidget.h"
#include "BasicData.h"
#include "BasicUserWidget.generated.h"

class UBasicUserWidget;
class UObject;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class BASICUI_API UBasicUserWidget : public UUserWidget {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBasicDataDelegate, UBasicUserWidget*, InOwner, const FBasicData&, InData);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBasicDataDelegate OnBasicDataChanged;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBasicData BasicData;
    
public:
    UBasicUserWidget();

    UFUNCTION(BlueprintCallable)
    void SetBasicDataObject(UObject* InObject);
    
    UFUNCTION(BlueprintCallable)
    void SetBasicDataIndex(int32 InIndex);
    
    UFUNCTION(BlueprintCallable)
    void SetBasicDataGuid(FGuid InGuid);
    
    UFUNCTION(BlueprintCallable)
    void SetBasicData(const FBasicData& InBasicData);
    
};

