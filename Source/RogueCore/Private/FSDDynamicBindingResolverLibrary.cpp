#include "FSDDynamicBindingResolverLibrary.h"
#include "Templates/SubclassOf.h"

UFSDDynamicBindingResolverLibrary::UFSDDynamicBindingResolverLibrary() {
}

ATemplateSequenceActor* UFSDDynamicBindingResolverLibrary::PlayTemplateSequence(UObject* WorldContextObject, APawn* Pawn, UTemplateSequenceCollection* Collection) {
    return NULL;
}

int32 UFSDDynamicBindingResolverLibrary::GetStoredPlayerCount(UObject* WorldContextObject) {
    return 0;
}

APlayerCharacter* UFSDDynamicBindingResolverLibrary::GetPlayerCharacterFromSequenceBinding(const FMovieSceneConditionContext& Context) {
    return NULL;
}

bool UFSDDynamicBindingResolverLibrary::GetMissionSuccessfull(UObject* WorldContextObject) {
    return false;
}

FMovieSceneDynamicBindingResolveResult UFSDDynamicBindingResolverLibrary::FsdResolveToPlayerCharacter(UObject* WorldContextObject, int32 PlayerControllerIndex, TSubclassOf<APlayerCharacter> EditorOverrideClass) {
    return FMovieSceneDynamicBindingResolveResult{};
}

FMovieSceneDynamicBindingResolveResult UFSDDynamicBindingResolverLibrary::FsdResolveToBosco(UObject* WorldContextObject, TSubclassOf<ABosco> EditorOverrideClass) {
    return FMovieSceneDynamicBindingResolveResult{};
}


