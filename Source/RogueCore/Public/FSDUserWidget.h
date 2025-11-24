#pragma once
#include "CoreMinimal.h"
#include "UObject/UnrealType.h"
#include "Blueprint/UserWidget.h"
#include "VisibilityChangedDelegateDelegate.h"
#include "FSDUserWidget.generated.h"

class AFSDPlayerState;
class AItem;
class APlayerCharacter;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UFSDUserWidget : public UUserWidget {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVisibilityChangedDelegate OnVisibilityChangedFSD;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    UFSDUserWidget();
    UFUNCTION(BlueprintCallable)
    void SetOpacity(float alpha);
    void ScaleByBaseResolution();
    void Refresh();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveNewVisibility(ESlateVisibility NewVisibility);
    void OnCloseMenuReleased(bool& Handled);
    void OnCloseMenuPressed(bool& Handled);
    bool HasCharacter();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetOpacity() const;
    AFSDPlayerState* GetFSDPlayerState();
    AItem* GetEquippedItem() const;
    float GetBaseResolutionScale() const;
    void BP_OnRefresh();
};
