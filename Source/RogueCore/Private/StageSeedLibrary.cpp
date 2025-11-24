#include "StageSeedLibrary.h"

UStageSeedLibrary::UStageSeedLibrary() {
}

FString UStageSeedLibrary::GetInvalidStageSeed() {
    return TEXT("");
}

FStageSeedParameters UStageSeedLibrary::DecodeStageSeed(const FString& SeedString) {
    return FStageSeedParameters{};
}

FString UStageSeedLibrary::CreateStageSeed(const FStageSeedParameters& Parameters) {
    return TEXT("");
}

FRunCreationParameters UStageSeedLibrary::ApplyStageSeed(const FRunCreationParameters& CreationParameters, const FString& SeedString) {
    return FRunCreationParameters{};
}


