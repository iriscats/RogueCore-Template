#pragma once
#include "CoreMinimal.h"
#include "BioBoosterInterfaceAudio.generated.h"

class UAudioComponent;
class USceneComponent;
class USoundCue;
USTRUCT(BlueprintType)
struct FBioBoosterInterfaceAudio {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> AudioRootComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* AudioSelectionStart;
    USoundCue* AudioSelectionSuccess;
    USoundCue* AudioSelectionFailed;
    USoundCue* AudioSelectionProgress;
    FName AudioSelectionProgressParam;
    TWeakObjectPtr<UAudioComponent> ProgressAudioComponent;
public:
    ROGUECORE_API FBioBoosterInterfaceAudio();
};
