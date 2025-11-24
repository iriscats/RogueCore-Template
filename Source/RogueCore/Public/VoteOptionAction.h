#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EVoteOptionActionType.h"
#include "VoteOptionAction.generated.h"

class AFSDPlayerState;
class UTexture2D;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UVoteOptionAction : public UObject {
    GENERATED_BODY()
public:
    UVoteOptionAction();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRunPersistent() const;
    
    EVoteOptionActionType GetVoteOptionActionType() const;
    FText GetTitle() const;
    UTexture2D* GetIcon() const;
    FText GetDescription() const;
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void ApplyAction(AFSDPlayerState* InPlayerState) const;
};
