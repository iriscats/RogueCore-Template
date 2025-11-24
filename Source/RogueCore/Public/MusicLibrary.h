#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MusicLibrary.generated.h"

class UMetaSoundSource;
class UMusicCategory;
class USoundCue;
UCLASS(Blueprintable)
class UMusicLibrary : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<USoundCue>> MusicCues;
    
    TArray<TSoftObjectPtr<UMetaSoundSource>> MusicMetaSounds;
    UMusicCategory* Category;
    UMusicLibrary();
};
