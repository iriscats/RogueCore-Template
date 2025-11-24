#pragma once
#include "CoreMinimal.h"
#include "GDKWinOptionsInSaveGame.generated.h"

USTRUCT(BlueprintType)
struct FGDKWinOptionsInSaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SaveGameOptionsValid;
    
    int32 ScreenMode;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ResolutionSizeX;
    uint32 ResolutionSizeY;
    bool bUseVSync;
    float FrameRateLimit;
    float Sharpening;
    int32 AntiAliasingType;
    float Gamma;
    int32 OverallQuality;
    float ResolutionScale;
    int32 TextureQuality;
    int32 ShadowQuality;
    int32 AntiAliasingQuality;
    int32 PostProcessingQuality;
    int32 EffectsQuality;
    int32 ViewDistanceQuality;
    bool PreventLatejoinCharacterDuplication;
    FString LocalGameServerName;
    FString CurrentAudioOutputDeviceId;
    bool UseDefaultAudioOutputDevice;
    ROGUECORE_API FGDKWinOptionsInSaveGame();
};
