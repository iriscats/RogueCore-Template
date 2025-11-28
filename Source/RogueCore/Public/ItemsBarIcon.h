#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemsBarIcon.generated.h"

class AItem;
class APlayerCharacter;
class UItemsBar;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UItemsBarIcon : public UUserWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool Selected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UItemsBar* ItemBar;
    APlayerCharacter* Character;
    AItem* Item;
    int32 Index;
    UItemsBarIcon();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnselect();
    void OnSelect();
    void OnInit();
};
