#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ActiveAudioItem.h"
#include "MusicHandle.h"
#include "MusicManager.generated.h"

class UMusicCategory;
class UMusicLibrary;
class USoundBase;
UCLASS(Blueprintable)
class UMusicManager : public UWorldSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    TMap<FMusicHandle, FActiveAudioItem> ActiveAudio;

    

    UMusicManager();

    UFUNCTION(BlueprintCallable)

    void StopTransitionMusic(float FadeOut);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FMusicHandle, FActiveAudioItem> ActiveAudio;
    
    UMusicManager();
    UFUNCTION(BlueprintCallable)
    void StopTransitionMusic(float FadeOut);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopHandle(FMusicHandle Handle);
    void StopCategory(UMusicCategory* Category);
    void StopAllMusic();
    void SetIsPaused(bool IsPaused);
    void PlayTransitionMusic(USoundBase* Music, float FadeIn);
    FMusicHandle PlayLibrary(UMusicLibrary* Library, int32 musicIndex);
    FMusicHandle Play(USoundBase* Music, UMusicCategory* Category);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTransitionMusicPlaying() const;
};
