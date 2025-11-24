#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BioBoosterReward.h"
#include "BioBoosterSelectorWidget.generated.h"

class ABioBoosterTerminal;
class UBioBoosterDeck;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UBioBoosterSelectorWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UBioBoosterSelectorWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Show();
    
    void SetTerminal(ABioBoosterTerminal* InTerminal);
    void SetProgress(float InProgress);
    void SetAvailableRewards(UBioBoosterDeck* InBioBoosterDeck, const TArray<FBioBoosterReward>& InRewards);
    int32 SelectReward();
    float GetIntroLength() const;
};
