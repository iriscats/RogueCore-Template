#pragma once
#include "CoreMinimal.h"
#include "ActorContextWidget.h"
#include "GymMinigameBaseWidget.generated.h"

class UTexture2D;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UGymMinigameBaseWidget : public UActorContextWidget {
    GENERATED_BODY()
public:
    UGymMinigameBaseWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetText(const FString& Text);
    
    void SetSecondaryHitAreaSize(float Size);
    void SetSecondaryHitAreaLocation(float PercentageValue);
    void SetRepTimerProgressbar(float Progress);
    void SetRepsLeft(int32 amount);
    void SetPersonalBest(int32 amount);
    void SetLives(int32 Lives);
    void SetHitAreaVisibility(bool visible, int32 Index);
    void SetHitAreaSize(float Size);
    void SetHitAreaLocation(float PercentageValue, int32 Index);
    void SetExerciseIcon(UTexture2D* Texture, const TArray<FString>& Name);
    void SetCrosshairAreaLocation(float Value);
    void IFrameChange(bool On);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetCrosshairHitSize();
};
