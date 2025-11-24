#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EGymDifficulty.h"
#include "GymActivityProperties.generated.h"

class UAnimSequence;
class UGymActivityStats;
class UResourceData;
class USoundCue;
class UTexture2D;
UCLASS(Blueprintable)
class UGymActivityProperties : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* AnimStart;
    
    UAnimSequence* AnimIdleUp;
    UAnimSequence* AnimIdleDown;
    UAnimSequence* AnimGoingUp;
    UAnimSequence* AnimGoingDown;
    UAnimSequence* AnimFailUp;
    UAnimSequence* AnimFailDown;
    UAnimSequence* AnimEnd;
    UAnimSequence* AnimAdditiveStruggleUp;
    UAnimSequence* AnimAdditiveStruggleDown;
    USoundCue* PointSound;
    USoundCue* SuccessSound;
    USoundCue* FailSound;
    UResourceData* CurrencyType;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGymDifficulty BaseDifficulty;
    EGymDifficulty MaxDifficulty;
    UTexture2D* GymIcon;
    TArray<FString> GymName;
    UTexture2D* GymIconRAW;
    bool SingleMotion;
    bool AlternativeVersion;
    UGymActivityStats* GymActivityStats;
    UGymActivityProperties();
};
