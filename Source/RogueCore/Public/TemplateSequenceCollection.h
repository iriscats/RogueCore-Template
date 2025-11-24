#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
//// #include "MovieScene/MovieSceneConditionContext.h" // Removed in UE5.6  // Removed in UE5.6
#include "ActorTemplateSequenceArray.h"
#include "Templates/SubclassOf.h"
#include "TemplateSequenceCollection.generated.h"

class AFSDGameState;
class APawn;
class UObject;
class UTemplateSequence;
UCLASS(Blueprintable)
class UTemplateSequenceCollection : public UDataAsset {
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<APawn>, FActorTemplateSequenceArray> ClassTemplateSequences;
    
    FActorTemplateSequenceArray FailedTemplateSequences;
    UTemplateSequenceCollection();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTemplateSequence* GetRandomTemplateSequence(const FMovieSceneConditionContext& Context) const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    UTemplateSequence* GetPlayerRandomTemplateSequence(UObject* WorldContextObject, APawn* Pawn, AFSDGameState* GameState) const;
};
