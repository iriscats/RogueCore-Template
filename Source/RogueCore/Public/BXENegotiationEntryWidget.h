#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BXEUnlockInstance.h"
#include "BXENegotiationEntryWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UBXENegotiationEntryWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBXEUnlockInstance UnlockInstance;
    
    int32 UnlockIndex;
    UBXENegotiationEntryWidget();
    UFUNCTION(BlueprintCallable)
    void SetUnlockInstance(const FBXEUnlockInstance& InUnlockInstance, int32 InIndex);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveUnlockChanged();
};
