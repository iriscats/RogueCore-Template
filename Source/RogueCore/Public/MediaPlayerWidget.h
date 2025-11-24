#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Blueprint/UserWidget.h"
#include "EMediaPlayerState.h"
#include "MediaPlayerWidget.generated.h"

class UFileMediaSource;
class UImage;
class UMediaPlayerWidget;
class UMediaTexture;
class USoundClass;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UMediaPlayerWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    UImage* OutputImage;

    UMediaPlayerWidget();

    UFUNCTION(BlueprintCallable)

    void Stop();



public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStateChanged, UMediaPlayerWidget*, InPlayerWidget, EMediaPlayerState, InState);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMediaPlayerEvent, UMediaPlayerWidget*, InPlayerWidget);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateChanged OnStateChanged;
    FMediaPlayerEvent OnEndReached;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush Brush;
    UFileMediaSource* MediaSource;
    UMediaTexture* MediaTexture;
    USoundClass* MediaSoundClass;
    float VolumeMultiplier;
    EMediaPlayerState PlayerState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* OutputImage;
    UMediaPlayerWidget();
    UFUNCTION(BlueprintCallable)
    void Stop();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveStateChanged(EMediaPlayerState InState);
    bool Play();
    void Callback_MediaPlayResumed();
    void Callback_MediaOpened(const FString& URL);
    void Callback_MediaEndReached();
    void Callback_MediaClosed();
};
