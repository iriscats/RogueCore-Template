#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Blueprint/UserWidget.h"
#include "SpriteRect.h"
#include "SpriteRectWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class USpriteRectWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FVector2D position;

    

    FVector2D Size;

    USpriteRectWidget();

    UFUNCTION(BlueprintCallable)

    void SetSize(FVector2D InSize);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D position;
    
    FVector2D Size;
    USpriteRectWidget();
    UFUNCTION(BlueprintCallable)
    void SetSize(FVector2D InSize);
    void SetPositionAndSize(FVector2D InPosition, FVector2D InSize);
    void SetPosition(FVector2D InPosition);
    void Move(FVector2D InOffset);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSpriteRect GetSpriteRect() const;
};
