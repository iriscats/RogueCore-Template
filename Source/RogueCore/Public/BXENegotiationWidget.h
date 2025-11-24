#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BXENegotiationData.h"
#include "BXENegotiationParticipant.h"
#include "BXEUnlockInstance.h"
#include "ItemSlotIndex.h"
#include "WindowWidget.h"
#include "BXENegotiationWidget.generated.h"

class AFSDPlayerState;
class APlayerState;
class UBXENegotiationParticipantComponent;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UBXENegotiationWidget : public UWindowWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UBXENegotiationParticipantComponent> participant;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBXENegotiationData NegotiationData;
    int32 SelectedUnlockIndex;
    int32 SelectedDroneUnlockIndex;
    UBXENegotiationWidget();
    UFUNCTION(BlueprintCallable)
    bool SelectUnlock(const FBXEUnlockInstance& InUnlock, FItemSlotIndex InUnlockSlot, int32 InUnlockIndex);
    bool SelectDroneUnlock(int32 InDroneUnlockIndex);
    bool RequestUnlock(int32 InUnlockIndex);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveUnlocksChanged(const TArray<FBXEUnlockInstance>& InPreviousUnlocks);
    void ReceiveTurnChanged(int32 InParticipantIndex, APlayerState* InParticipant);
    void ReceiveParticipantsChanged(const TArray<FBXENegotiationParticipant>& InParticipants);
    void ReceiveParticipantCursorChanged(AFSDPlayerState* InPlayerState, FVector2D InViewPortPos);
    void ReceiveDataChanged();
    void ReceiveBeginSelectDroneUnlock();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUnlockSelected(int32 InUnlockIndex) const;
    bool IsNegotiationFinishing() const;
    TArray<AFSDPlayerState*> GetUnlockSelectedBy(int32 InIndex) const;
    TArray<AFSDPlayerState*> GetUnlockRequestedBy(int32 InUnlockIndex);
    bool GetIsMyTurnPending() const;
    bool GetIsItMyTurn() const;
};