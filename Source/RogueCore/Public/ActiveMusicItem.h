#pragma once
#include "CoreMinimal.h"
#include "MusicHandle.h"
#include "ActiveMusicItem.generated.h"

class UMusicCategory;
class USoundBase;
USTRUCT(BlueprintType)
struct FActiveMusicItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundBase* Sound;
    
    float StartingTime;
    float FadeDuration;
    bool Looping;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NotReplicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMusicHandle> Handles;
    UMusicCategory* Category;
    ROGUECORE_API FActiveMusicItem();
};
