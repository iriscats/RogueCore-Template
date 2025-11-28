#pragma once
#include "CoreMinimal.h"

#include "Styling/SlateBrush.h"
#include "BasicBrush.h"
#include "BasicColor.h"
#include "BasicMaterialParameters.h"
#include "BasicUserWidget.h"
#include "BasicImage.generated.h"

class UImage;
class UMaterialInstanceDynamic;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class BASICUI_API UBasicImage : public UBasicUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBasicBrush Brush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBasicColor BrushColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBasicMaterialParameters MaterialParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UImage* InnerImage;
    
public:
    UBasicImage();

    UFUNCTION(BlueprintCallable)
    void SetDynamicMaterialVector(FName InName, FVector4 InVector);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicMaterialTexture(FName InName, UTexture2D* InTexture);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicMaterialScalar(FName InName, float InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicMaterialParameters(FBasicMaterialParameters InParameters);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicMaterialColor(FName InName, FBasicColor InColor);
    
    UFUNCTION(BlueprintCallable)
    void SetBrushFromTexture(UTexture2D* InTexture, bool InMatchSize);
    
    UFUNCTION(BlueprintCallable)
    void SetBrushColor(FBasicColor InColor);
    
    UFUNCTION(BlueprintCallable)
    void SetBrush(FBasicBrush InBrush);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSlateBrush GetSlateBrush();
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetDynamicMaterial();
    
};

