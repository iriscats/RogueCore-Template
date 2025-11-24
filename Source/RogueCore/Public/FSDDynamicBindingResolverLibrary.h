#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
// #include "MovieScene/MovieSceneConditionContext.h" // Removed in UE5.6
#include "Runtime/MovieScene/Public/MovieSceneDynamicBinding.h"
#include "Templates/SubclassOf.h"
#include "FSDDynamicBindingResolverLibrary.generated.h"

class ABosco;
class APawn;
class APlayerCharacter;
class ATemplateSequenceActor;
class UObject;
class UTemplateSequenceCollection;
UCLASS(Blueprintable, MinimalAPI)
class UFSDDynamicBindingResolverLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFSDDynamicBindingResolverLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ATemplateSequenceActor* PlayTemplateSequence(UObject* WorldContextObject, APawn* Pawn, UTemplateSequenceCollection* Collection);
    
    static int32 GetStoredPlayerCount(UObject* WorldContextObject);
    UFUNCTION(BlueprintCallable)
    static APlayerCharacter* GetPlayerCharacterFromSequenceBinding(const FMovieSceneConditionContext& Context);
    static bool GetMissionSuccessfull(UObject* WorldContextObject);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FMovieSceneDynamicBindingResolveResult FsdResolveToPlayerCharacter(UObject* WorldContextObject, int32 PlayerControllerIndex, TSubclassOf<APlayerCharacter> EditorOverrideClass);
    static FMovieSceneDynamicBindingResolveResult FsdResolveToBosco(UObject* WorldContextObject, TSubclassOf<ABosco> EditorOverrideClass);
};
