#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
// #include "MovieScene/MovieSceneConditionContext.h" // Removed in UE5.6
#include "AnimSequenceArray.h"
#include "AnimSequenceCollection.generated.h"

class UAnimSequence;
class UPlayerCharacterID;
UCLASS(Blueprintable)
class UAnimSequenceCollection : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UPlayerCharacterID*, FAnimSequenceArray> ClassAnims;
    
    UAnimSequenceCollection();
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimSequence* GetRandomAnimSequence(const FMovieSceneConditionContext& Context) const;
};
