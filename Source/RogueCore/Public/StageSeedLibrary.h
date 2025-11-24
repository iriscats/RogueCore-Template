#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RunCreationParameters.h"
#include "StageSeedParameters.h"
#include "StageSeedLibrary.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UStageSeedLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UStageSeedLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetInvalidStageSeed();
    
    static FStageSeedParameters DecodeStageSeed(const FString& SeedString);
    static FString CreateStageSeed(const FStageSeedParameters& Parameters);
    static FRunCreationParameters ApplyStageSeed(const FRunCreationParameters& CreationParameters, const FString& SeedString);
};
