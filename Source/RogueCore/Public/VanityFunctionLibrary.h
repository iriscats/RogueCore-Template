#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VanityFunctionLibrary.generated.h"

class APlayerCharacter;
class UObject;
class UPlayerCharacterID;
UCLASS(Blueprintable)
class ROGUECORE_API UVanityFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UVanityFunctionLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RandomizeVanityLoadout(UObject* WorldContextObject, APlayerCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void RandomizeAllRandomVanityLoadout(APlayerCharacter* currentCharacter);
    static void CopyPasteVanityLoadout(UObject* WorldContextObject, UPlayerCharacterID* PlayerId, int32 fromIndex, int32 toIndex);
};
